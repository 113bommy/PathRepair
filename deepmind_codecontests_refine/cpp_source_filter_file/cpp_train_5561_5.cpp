#include <bits/stdc++.h>
using namespace std;
struct node {
  long long y;
  node* left;
  node* right;
};
int n, m, k;
char g[3000][3000];
vector<int> pos[3000];
int cur[3000];
node sweep[7 * 3000 + 3000];
long long total = 0;
vector<int> ones;
vector<int> take[3000];
vector<int> loc[3000];
long long cur_tot = 0;
long long get_count(node* moo) {
  long long a = moo->y - moo->left->y;
  if (k == 0) return a * (a - 1) / 2;
  for (int i = 0; i < k; i++) moo = moo->right;
  long long b = moo->y - moo->left->y;
  return a * b;
}
void build_list() {
  for (int i = 0; i < (int)ones.size(); i++) {
    sweep[i].y = ones[i];
    if (i > 0)
      sweep[i].left = &sweep[i - 1];
    else
      sweep[i].left = NULL;
    if (i + 1 < (int)ones.size())
      sweep[i].right = &sweep[i + 1];
    else
      sweep[i].right = NULL;
    if (ones[i] >= 0 && ones[i] < n) {
      loc[ones[i]].push_back(i);
    }
  }
  for (int i = 0; i < (int)ones.size(); i++) {
    if (ones[i] >= 0 && ones[i] < n) {
      cur_tot += get_count(&sweep[i]);
    }
  }
  if (k == 0) cur_tot += get_count(&sweep[ones.size() - 1]);
}
void remove_node(node* moo) {
  cur_tot -= get_count(moo);
  cur_tot -= get_count(moo->right);
  node* two = moo;
  for (int i = 0; i < k; i++) {
    two = two->left;
    cur_tot -= get_count(two);
  }
  two = moo->left;
  node* three = moo->right;
  three->left = two;
  two->right = three;
  cur_tot += get_count(three);
  two = three;
  for (int i = 0; i < k; i++) {
    two = two->left;
    cur_tot += get_count(two);
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", g[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '1') pos[j].push_back(i);
    }
  }
  memset(cur, 0, sizeof(cur));
  for (int i = 0; i < n; i++) {
    ones.clear();
    cur_tot = 0;
    for (int j = 0; j < n; j++) take[j].clear();
    for (int j = 0; j <= k; j++) ones.push_back(-1);
    for (int j = 0; j < m; j++) {
      loc[j].clear();
      if (cur[j] != (int)pos[j].size() && pos[j][cur[j]] < i) cur[j]++;
      for (int l = 0; l <= min(k, (int)pos[j].size() - cur[j] - 1); l++) {
        ones.push_back(j);
        take[pos[j][l + cur[j]]].push_back(j);
      }
    }
    for (int j = 0; j <= k; j++) ones.push_back(n);
    build_list();
    for (int j = m - 1; j >= i; j--) {
      total += cur_tot;
      if (j == i) break;
      for (int l = 0; l < (int)take[j].size(); l++) {
        int v = take[j][l];
        int w = loc[v][loc[v].size() - 1];
        loc[v].pop_back();
        remove_node(&sweep[w]);
      }
    }
  }
  cout << total << "\n";
}
