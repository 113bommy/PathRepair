#include <bits/stdc++.h>
using namespace std;
int pre[26];
void Initialize() {
  for (int i = 0; i < 26; ++i) {
    pre[i] = i;
  }
}
int Find(int a) {
  int root = a;
  while (pre[root] != root) {
    root = pre[root];
  }
  while (pre[a] != root) {
    int tmp = pre[a];
    pre[a] = root;
    a = tmp;
  }
  return root;
}
void Join(int a, int b) {
  int root_a = Find(a);
  int root_b = Find(b);
  if (root_a < root_b) pre[root_b] = root_a;
  if (root_a > root_b) pre[root_a] = root_b;
}
int main(int argc, char const *argv[]) {
  char s1[100001], s2[10001];
  int n;
  scanf("%d %s %s", &n, s1, s2);
  Initialize();
  for (int i = 0; i < n; ++i) {
    if (s1[i] != s2[i]) {
      Join(s1[i] - 'a', s2[i] - 'a');
    }
  }
  vector<pair<int, int> > ans;
  for (int i = 0; i < 26; ++i) {
    if (pre[i] != i) ans.push_back(make_pair(i, pre[i]));
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%c %c\n", ans[i].first + 'a', ans[i].second + 'a');
  }
  return 0;
}
