#include <bits/stdc++.h>
int parent(int *set, int child) {
  if (set[child] < 0) return child;
  return parent(set, set[child]);
}
int *merge(int *set, int to, int what) {
  set[parent(set, to)]--;
  set[what] = to;
  return set;
}
int chain_len(int *set, int node) {
  if (set[node] < 0) return 1;
  return chain_len(set, set[node]) + 1;
}
int main(void) {
  std::map<std::string, int> names;
  names["polycarp"] = 0;
  int n;
  scanf("%d", &n);
  ;
  int *set = (int *)(malloc(sizeof(int) * n + 1));
  memset(set, -1, sizeof(set));
  std::string a, b, c;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    std::cin >> a >> c >> b;
    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    if (names.find(a) == names.end()) names[a] = cnt++;
    set = merge(set, names[b], names[a]);
  }
  int maxx = 0;
  for (int i = 0; i < n + 1; i++) {
    if (set[i] >= 0) {
      int chain = chain_len(set, i);
      if (chain > maxx) maxx = chain;
    }
  }
  printf("%d", maxx + 1);
  ;
  return 0;
}
