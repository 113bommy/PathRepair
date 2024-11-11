#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  sort(a.begin(), a.begin());
  for (int j = 0; j < (n+2)/3; ++j) a[n] ^= a[j] ^ a[j + n/3] ^ a[j + n/3*2];
  cout << (a[n] ? "No" : "Yes");
  return 0;
}
	