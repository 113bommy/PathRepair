#include <bits/stdc++.h>
using namespace std;
long n;
string s;
long mi = 1e9;
int main() {
  cin >> n >> s;
  for (long i = 2; i <= 2; i++) {
    long cnt = 0;
    if (s[i] != 'A') {
      long tmp = int(s[i]) - 65;
      long tmp2 = 91 - int(s[i]);
      cnt += min(tmp, tmp2);
    }
    if (s[i + 1] != 'C') {
      if (int(s[i + 1]) < 67)
        cnt += 67 - int(s[i + 1]);
      else {
        long tmp = int(s[i + 1]) - 67;
        long tmp2 = 93 - int(s[i + 1]);
        cnt += min(tmp, tmp2);
      }
    }
    if (s[i + 2] != 'T') {
      if (int(s[i + 2]) > 84)
        cnt += int(s[i + 2]) - 84;
      else {
        long tmp = int(s[i + 2]) - 64 + 90 - 84;
        long tmp2 = 84 - int(s[i + 2]);
        cnt += min(tmp, tmp2);
      }
    }
    if (s[i + 3] != 'G') {
      if (int(s[i + 3]) < 71)
        cnt += (71 - int(s[i + 3]));
      else {
        long tmp = 97 - int(s[i + 3]);
        long tmp2 = int(s[i + 3]) - 71;
        cnt += min(tmp, tmp2);
      }
    }
    mi = min(mi, cnt);
  }
  cout << mi;
}
