#include <bits/stdc++.h>
using namespace std;
int readint() {
  char c;
  while (c = getchar(), (c < '0' || c > '9') && c != '-')
    ;
  bool flag = (c == '-');
  if (flag) c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  return flag ? -x : x;
}
inline string tos(int x) {
  string s;
  while (x) s = (char)(x % 10 + '0') + s, x /= 10;
  return s;
}
int have[5], cnt[5];
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, n, t;
  cin >> n;
  have[2] = n * 2;
  have[4] = n;
  for (i = 0; i < n; i++) {
    cin >> t;
    while (t > 2) {
      if (have[4])
        have[4]--, t -= 4;
      else if (have[2])
        have[2]--, t -= 2;
      else {
        cout << "NO";
        return 0;
      }
    }
    if (t) cnt[t]++;
  }
  while (cnt[2]) {
    if (have[2])
      cnt[2]--, have[2]--;
    else if (have[4])
      have[4]--, cnt[2]--, have[1]++;
    else
      cnt[2]--, cnt[1] += 2;
  }
  if (cnt[1] > have[1] + have[2] + have[4] * 2) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
