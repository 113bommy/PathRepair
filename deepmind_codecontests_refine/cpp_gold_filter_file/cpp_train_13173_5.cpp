#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c = 0, cn = 0, cnt = 0;
  long long mx = -1, mxx = -1, mxxx = -1;
  long long n, d;
  cin >> n >> d;
  string s;
  for (int i = 0; i < d; i++) {
    cin >> s;
    if (s.find('0') != -1) {
      c++;
    } else {
      cnt = max(c, cnt);
      c = 0;
    }
  }
  cout << max(c, cnt) << endl;
  return 0;
}
