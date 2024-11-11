#include <bits/stdc++.h>
using namespace std;
int n, k, a, p;
vector<int> v, l;
set<long long> q;
bool f = false;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
    if (!f) {
      printf("1 %d\n", v[i]);
      p++;
      if (p == k) return 0;
    }
  for (int i = n - 1; i >= 0; i--) {
    l.push_back(v[i]);
    for (int j = i - 1; j >= 0; j--) {
      printf("%d ", l.size() + 1);
      for (int f = 0; f < l.size(); f++) printf("%d ", l[f]);
      printf("%d\n", v[j]);
      p++;
      if (p == k) return 0;
    }
  }
  return 0;
}
