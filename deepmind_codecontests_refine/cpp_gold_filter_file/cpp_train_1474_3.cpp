#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n, 0);
  int m = INT_MIN;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    m = max(m, a[i]);
  }
  vector<int> cnt(m + 1, 0);
  for (int i = 0; i < n; i++) {
    if (cnt[a[i]] >= 2) {
      cout << "NO";
      return 0;
    } else
      cnt[a[i]]++;
  }
  cout << "YES\n";
  sort(a.begin(), a.end());
  vector<int> inc;
  vector<int> dec;
  int i = 0;
  while (i < n) {
    inc.push_back(a[i]);
    i += 2;
  }
  i = 1;
  while (i < n) {
    dec.push_back(a[i]);
    i += 2;
  }
  cout << inc.size() << "\n";
  for (int i = 0; i < (int)inc.size(); i++) cout << inc[i] << " ";
  cout << "\n";
  cout << dec.size() << "\n";
  for (int i = (int)dec.size() - 1; i >= 0; i--) cout << dec[i] << " ";
  cout << "\n";
}
