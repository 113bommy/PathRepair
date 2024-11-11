#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
bool gw[26];
int main() {
  string g;
  cin >> g;
  for (int i = 0; i < g.length(); i += 1) {
    gw[(int)(g[i] - 'a')] = 1;
  }
  string t;
  cin >> t;
  int n;
  cin >> n;
  for (int i = 0; i < n; i += 1) {
    string tmp;
    cin >> tmp;
    bool flag = false;
    int tmplen = tmp.length();
    int idx = 0;
    int head = -1;
    int btm = -1;
    int left = 0;
    int right = 0;
    for (int j = 0; j < tmplen; j += 1) {
      left++;
      if (t[idx] == '?') {
        if (gw[(int)(tmp[j] - 'a')]) {
          idx++;
        } else {
          flag = true;
          break;
        }
      } else if (t[idx] == '*') {
        head = j;
        break;
      } else {
        if (t[idx] == tmp[j]) {
          idx++;
        } else {
          flag = true;
          break;
        }
      }
    }
    if (flag) {
      cout << "NO" << endl;
    } else if (head != -1) {
      idx = t.length() - 1;
      for (int j = tmplen - 1; j >= 0; j--) {
        right++;
        if (t[idx] == '?') {
          if (gw[(int)(tmp[j] - 'a')]) {
            idx--;
          } else {
            flag = true;
            break;
          }
        } else if (t[idx] == '*') {
          btm = j;
          break;
        } else {
          if (t[idx] == tmp[j]) {
            idx--;
          } else {
            flag = true;
            break;
          }
        }
      }
      if (flag) {
        cout << "NO" << endl;
      } else if (btm == -1) {
        if (right == t.length() - 1) {
          if (t[0] == '*')
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
        } else {
          cout << "NO" << endl;
        }
      } else {
        bool flag2 = false;
        for (int p = head; p <= btm; p++) {
          if (gw[(int)(tmp[p] - 'a')]) flag2 = true;
        }
        if (flag2) {
          cout << "NO" << endl;
        } else if (head > btm) {
          cout << "NO" << endl;
        } else {
          cout << "YES" << endl;
        }
      }
    } else {
      if (left == t.length()) {
        cout << "YES" << endl;
      } else if (left == t.length() - 1) {
        if (t[t.length() - 1] == '*')
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else
        cout << "NO" << endl;
    }
  }
  return 0;
}
