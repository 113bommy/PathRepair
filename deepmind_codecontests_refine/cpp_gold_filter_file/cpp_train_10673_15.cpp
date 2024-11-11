#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int freq[n + 1];
    for (int i = 0; i <= n; i++) freq[i] = 0;
    int mx = 0, ans = v[i];
    for (int j = i; j < n; j++) {
      freq[v[j]]++;
      if (freq[v[j]] > mx) mx = freq[v[j]], ans = v[j];
      if (freq[v[j]] == mx && ans > v[j]) ans = min(ans, v[j]);
      mp[ans]++;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", mp[i]);
  printf("\n");
  return 0;
}
