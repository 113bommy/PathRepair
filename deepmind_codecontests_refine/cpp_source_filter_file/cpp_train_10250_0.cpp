#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a(26);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[c - 'A']++;
  }
  sort(a.begin(), a.end());
  long long s = 0;
  for (int i = 25; i >= 0 && k > 0; i--) {
    int x = min(k, a[i]);
    k -= x;
    s += x * x;
  }
  cout << s << endl;
  return 0;
}
