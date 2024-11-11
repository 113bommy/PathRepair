#include <bits/stdc++.h>
using namespace std;
int N, M, Q, B;
int init[100010];
vector<int> sets[100010];
long long initsum[100010];
int bigsetID[100010];
int common[350][100010];
bool iselement[100010];
void pre(void) {
  int i, j, k;
  for ((i) = 0; (i) < (int)(M); (i)++)
    for ((j) = 0; (j) < (int)(sets[i].size()); (j)++)
      initsum[i] += init[sets[i][j]];
  for ((i) = 0; (i) < (int)(M); (i)++) bigsetID[i] = -1;
  B = 0;
  for ((i) = 0; (i) < (int)(M); (i)++)
    if (sets[i].size() >= 300) {
      bigsetID[i] = B;
      B++;
    }
  for ((i) = 0; (i) < (int)(M); (i)++)
    if (bigsetID[i] != -1) {
      int id = bigsetID[i];
      for ((j) = 0; (j) < (int)(N); (j)++) iselement[j] = false;
      for ((j) = 0; (j) < (int)(sets[i].size()); (j)++)
        iselement[sets[i][j]] = true;
      for ((j) = 0; (j) < (int)(M); (j)++)
        for ((k) = 0; (k) < (int)(sets[j].size()); (k)++)
          if (iselement[sets[j][k]]) common[id][j]++;
    }
}
long long add_big_set[350];
long long add_set[100010];
long long add_element[100010];
long long big_set_sum[350];
long long sum_query(int id) {
  int i;
  long long ans = initsum[id];
  if (bigsetID[id] != -1) {
    ans += big_set_sum[bigsetID[id]];
    return ans;
  }
  for ((i) = 0; (i) < (int)(B); (i)++) ans += add_big_set[i] * common[i][id];
  for ((i) = 0; (i) < (int)(sets[id].size()); (i)++)
    ans += add_element[sets[id][i]];
  return ans;
}
void add_query(int id, int val) {
  int i;
  for ((i) = 0; (i) < (int)(B); (i)++)
    big_set_sum[i] += common[i][id] * (long long)val;
  if (bigsetID[id] != -1) add_big_set[bigsetID[id]] += val;
  if (bigsetID[id] == -1)
    for ((i) = 0; (i) < (int)(sets[id].size()); (i)++)
      add_element[sets[id][i]] += val;
}
char buf[10];
void read_query(void) {
  int id, val;
  scanf("%s", buf);
  if (buf[0] == '?') {
    scanf("%d", &id);
    id--;
    long long ans = sum_query(id);
    printf("%I64d\n", ans);
  } else {
    scanf("%d%d", &id, &val);
    id--;
    add_query(id, val);
  }
}
int main(void) {
  int i, j;
  cin >> N >> M >> Q;
  for ((i) = 0; (i) < (int)(N); (i)++) scanf("%d", &init[i]);
  for ((i) = 0; (i) < (int)(M); (i)++) {
    int sz, x;
    scanf("%d", &sz);
    for ((j) = 0; (j) < (int)(sz); (j)++) {
      scanf("%d", &x);
      x--;
      sets[i].push_back(x);
    }
  }
  pre();
  for ((i) = 0; (i) < (int)(Q); (i)++) read_query();
  return 0;
}
