#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int l = 0;
  int r = n - 1;
  int cnt = 0;
  vector<int> test;
  while (l < n && r >= 0) {
    int num = a[l] + b[r];
    if (num >= k) {
      test.push_back(num);
      l++;
      r--;
    } else {
      l++;
    }
  }
  cout << 1 << " " << test.size() << endl;
}
