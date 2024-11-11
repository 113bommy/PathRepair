#include <bits/stdc++.h>
using namespace std;
int n, a[110], s[110], t[110], sl[110], tl[110];
bool shure[110];
bool resolv(int pos) {
  if (pos > n) return true;
  if (pos == n) return s[n] - s[n - 1] == (a[n - 1] + 1) * (a[n - 2] + 1);
  if (pos == n - 1)
    return s[n - 1] - s[n - 2] ==
               (a[n - 3] + 1) * (a[n - 2] + 1) + (a[n - 2] + 1) * a[n] &&
           resolv(n);
  if (pos == 1) {
    if (s[1] - s[0] == a[2] * a[3] && resolv(2)) return true;
    if (!shure[3]) a[3] = 1;
    if (s[1] - s[0] == a[2] * a[3] && resolv(2)) return true;
    if (!shure[2]) a[2] = 1;
    if (!shure[3]) a[3] = 0;
    if (s[1] - s[0] == a[2] * a[3] && resolv(2)) return true;
    if (!shure[3]) a[3] = 1;
    if (s[1] - s[0] == a[2] * a[3] && resolv(2)) return true;
    if (!shure[1]) a[1] = 1;
    if (!shure[2]) a[2] = 0;
    if (!shure[3]) a[3] = 0;
    if (s[1] - s[0] == a[2] * a[3] && resolv(2)) return true;
    if (!shure[3]) a[3] = 1;
    if (s[1] - s[0] == a[2] * a[3] && resolv(2)) return true;
    if (!shure[2]) a[2] = 1;
    if (!shure[3]) a[3] = 0;
    if (s[1] - s[0] == a[2] * a[3] && resolv(2)) return true;
    if (!shure[3]) a[3] = 1;
    return s[1] - s[0] == a[2] * a[3] && resolv(2);
  }
  if (pos == 2) {
    if (s[2] - s[1] == (a[1] + 1) * a[3] + a[3] * a[4] && resolv(3))
      return true;
  } else if (s[pos] - s[pos - 1] == (a[pos - 2] + 1) * (a[pos - 1] + 1) +
                                        (a[pos - 1] + 1) * a[pos + 1] +
                                        a[pos + 1] * a[pos + 2] &&
             resolv(pos + 1))
    return true;
  if (!shure[pos + 2]) a[pos + 2] = 1;
  if (pos == 2)
    if (s[2] - s[1] == (a[1] + 1) * a[3] + a[3] * a[4] && resolv(3))
      return true;
  if (s[pos] - s[pos - 1] == (a[pos - 2] + 1) * (a[pos - 1] + 1) +
                                 (a[pos - 1] + 1) * a[pos + 1] +
                                 a[pos + 1] * a[pos + 2] &&
      resolv(pos + 1))
    return true;
  if (!shure[pos + 2]) a[pos + 2] = 0;
  return false;
}
int main() {
  cin >> n;
  cin >> t[0];
  cin >> s[0];
  cout << "+ " << 3 << endl;
  cin >> t[3];
  cin >> s[3];
  cout << "+ " << 1 << endl;
  cin >> t[1];
  cin >> s[1];
  cout << "+ " << 2 << endl;
  cin >> t[2];
  cin >> s[2];
  cout << "+ " << 1 << endl;
  cin >> tl[1];
  cin >> sl[1];
  for (a[1] = 0; a[1] * (a[1] + 1) != 2 * (tl[1] - t[2]); a[1]++)
    ;
  if (t[3] - t[0]) {
    for (a[3] = 2; a[3] * (a[3] - 1) != 2 * (t[3] - t[0]); a[3]++)
      ;
    a[2] = (s[1] - s[3]) / (a[3] + 1);
  } else {
    if (t[2] - t[1]) {
      for (a[2] = 2; a[2] * (a[2] - 1) != 2 * (t[2] - t[1]); a[2]++)
        ;
      a[3] = (s[1] - s[3]) / a[2] - 1;
    } else {
      if (s[1] - s[3]) {
        a[2] = 1;
        a[3] = (s[1] - s[3]) - 1;
      } else {
        a[2] = 0;
        a[3] = sl[1] - s[2] - 1;
      }
    }
  }
  a[4] = (s[2] - s[1]) / (a[3] + 1) - a[1] - 1;
  for (int i = 5; i + 3 <= n; i += 4) {
    cout << "+ " << i + 2 << endl;
    cin >> t[i + 2];
    cin >> s[i + 2];
    cout << "+ " << i << endl;
    cin >> t[i];
    cin >> s[i];
    cout << "+ " << i + 1 << endl;
    cin >> t[i + 1];
    cin >> s[i + 1];
    cout << "+ " << i << endl;
    cin >> tl[i];
    cin >> sl[i];
    for (a[i] = 0; a[i] * (a[i] + 1) != 2 * (tl[i] - t[i + 1]); a[i]++)
      ;
    if (t[i + 2] - tl[i - 4]) {
      for (a[i + 2] = 2;
           a[i + 2] * (a[i + 2] - 1) != 2 * (t[i + 2] - tl[i - 4]); a[i + 2]++)
        ;
      a[i + 1] = (s[i] - s[i + 2] - (a[i - 2] + 1) * a[i - 1]) /
                 (a[i - 1] + a[i + 2] + 1);
    } else {
      if (t[i + 1] - t[i]) {
        for (a[i + 1] = 2; a[i + 1] * (a[i + 1] - 1) != 2 * (t[i + 1] - t[i]);
             a[i + 1]++)
          ;
        a[i + 2] = (s[i] - s[i + 2] - (a[i - 2] + 1) * a[i - 1]) / a[i + 1] -
                   a[i - 1] - 1;
      } else {
        if (s[i] - s[i + 2] - (a[i - 2] + 1) * a[i - 1]) {
          a[i + 1] = 1;
          a[i + 2] = s[i] - s[i + 2] - (a[i - 2] + 1) * a[i - 1] - a[i - 1] - 1;
        } else {
          a[i + 1] = 0;
          a[i + 2] =
              sl[i] - s[i + 1] - (a[i - 2] + 1) * a[i - 1] - a[i - 1] - 1;
        }
      }
    }
    a[i + 3] = (s[i + 1] - s[i] - a[i - 1] * (a[i] + 1) -
                (a[i] + 1) * (a[i + 2] + 1)) /
               (a[i + 2] + 1);
  }
  if (n % 4 == 1) {
    cout << "+ " << n - 1 << endl;
    cin >> tl[n - 1];
    cin >> sl[n - 1];
    a[n] = (sl[n - 1] - sl[n - 4] - (a[n - 3] + 1) * (a[n - 2] + 1)) /
           (a[n - 2] + 1);
  } else if (n % 4 == 2) {
    cout << "+ " << n - 2 << endl;
    cin >> tl[n - 2];
    cin >> sl[n - 2];
    cout << "+ " << n - 1 << endl;
    cin >> t[n - 1];
    cin >> s[n - 1];
    if (t[n - 1] - tl[n - 2])
      for (a[n - 1] = 2;
           a[n - 1] * (a[n - 1] - 1) != 2 * (t[n - 1] - tl[n - 2]); a[n - 1]++)
        ;
    else {
      if (sl[n - 2] - sl[n - 5] - (a[n - 4] + 1) * (a[n - 3] + 1))
        a[n - 1] = 1;
      else
        a[n - 1] = 0;
    }
    a[n] = (s[n - 1] - sl[n - 2] - (a[n - 2] + 1) * (a[n - 3] + 1)) /
           (a[n - 2] + 1);
  } else if (n % 4 == 3) {
    cout << "+ " << n - 3 << endl;
    cin >> tl[n - 3];
    cin >> sl[n - 3];
    cout << "+ " << n - 2 << endl;
    cin >> t[n - 2];
    cin >> s[n - 2];
    cout << "+ " << n - 1 << endl;
    cin >> t[n - 1];
    cin >> s[n - 1];
    if (t[n - 2] - tl[n - 3])
      for (a[n - 2] = 2;
           a[n - 2] * (a[n - 2] - 1) != 2 * (t[n - 2] - tl[n - 3]); a[n - 2]++)
        ;
    else {
      if (sl[n - 3] - sl[n - 6] - (a[n - 5] + 1) * (a[n - 4] + 1))
        a[n - 2] = 1;
      else
        a[n - 2] = 0;
    }
    if (t[n - 1] - t[n - 2])
      for (a[n - 1] = 2; a[n - 1] * (a[n - 1] - 1) != 2 * (t[n - 1] - t[n - 2]);
           a[n - 1]++)
        ;
    else {
      if (s[n - 2] - sl[n - 3] - (a[n - 4] + 1) * (a[n - 3] + 1))
        a[n - 1] = 1;
      else
        a[n - 1] = 0;
    }
    a[n] = (s[n - 1] - s[n - 2] - (a[n - 2] + 1) * (a[n - 3] + 1)) /
           (a[n - 2] + 1);
  }
  cout << "!";
  for (int i = 1; i <= n; i++) cout << " " << a[i];
  cout << endl;
  return 0;
}
