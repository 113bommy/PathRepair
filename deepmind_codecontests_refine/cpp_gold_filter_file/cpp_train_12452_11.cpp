#include <bits/stdc++.h>
using namespace std;
const int MIN = -1000000;
int n, fc, lc;
string s;
vector<int> p;
bool po(int d) {
  int ki = 0;
  int k = p[ki];
  for (int i = fc; i <= lc; i++) {
    if (s[i] == '*') {
      while (i > k + d) {
        if (k == MIN) return false;
        ki++;
        k = p[ki];
      }
      if (i > k) {
        i = k + d;
      } else {
        if (i < k - d) return false;
        int kmi = k - i;
        i = k + max((d - kmi) / 2, d - (2 * kmi));
      }
      ki++;
      k = p[ki];
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'P') {
      p.push_back(i);
    }
  }
  p.push_back(MIN);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      fc = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '*') {
      lc = i;
      break;
    }
  }
  int max = 2 * n;
  int min = 0;
  while (max - min > 0) {
    int mid = (min + max) / 2;
    if (po(mid)) {
      max = mid;
    } else {
      min = mid + 1;
    }
  }
  cout << min;
}
