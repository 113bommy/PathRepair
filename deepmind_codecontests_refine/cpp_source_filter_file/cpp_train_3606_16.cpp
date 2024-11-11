#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_set<int> s;
  for (int i = 1; i <= 1000; i++) s.insert(i * i);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  for (int i = 0; i < n; i++) {
    if (s.find(a[i]) == s.end()) {
      cout << a[i];
      return 0;
    }
  }
}
