#include <bits/stdc++.h>
using namespace std;
long long poly[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int unk = -1;
  int unkCount = 0;
  for (int i = 0; i <= n; i++) {
    string s;
    cin >> s;
    if (s[0] == '?') {
      if (unk == -1) unk = i;
      unkCount++;
    } else {
      poly[i] = atoi(s.c_str());
    }
  }
  bool ans = false;
  if (k == 0) {
    if (unkCount == 0) {
      ans = (poly[0] == 0);
    } else {
      if (unk == 0) {
        ans = ((n + 1 - unkCount) % 2 == 1);
      } else {
        ans = (poly[0] == 0);
      }
    }
  } else {
    if (unkCount >= 1) {
      ans = (n % 2 == 1);
    } else {
      ans = true;
      srand(1279328);
      for (int trial = 0; trial < 100; trial++) {
        long long mod = rand() + n;
        long long blah = 0;
        for (int i = n; i >= 0; i--) {
          blah = ((blah * k + poly[i]) % mod);
        }
        if (blah != 0) {
          ans = false;
          break;
        }
      }
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
