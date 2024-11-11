#include <bits/stdc++.h>
using namespace std;
long long cnt, mini = 1e9, maxi = -1;
long long n, m, k, x;
long long mini1 = 1e9, maxi1 = -1, cnt1, cnt2, cnt3, ans, sum;
int main() {
  ios_base::sync_with_stdio(0);
  string a, s;
  cin >> a;
  s = a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'C' || a[i] == 'B' || a[i] == 'D' || a[i] == 'E' ||
        a[i] == 'F' || a[i] == 'G' || a[i] == 'J' && a[i] == 'K' ||
        a[i] == 'L' || a[i] == 'N' || a[i] == 'P' || a[i] == 'Q' ||
        a[i] == 'R' || a[i] == 'S' || a[i] == 'Z') {
      cout << "NO";
      return 0;
    }
  }
  reverse(s.begin(), s.end());
  if (a == s) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
