#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
bool used[1000000];
int n, t, tut, pnt = -1;
string s;
bool flag = false;
vector<int> v;
int main() {
  cin >> n >> t;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      flag = true;
    }
    if (!flag) continue;
    if (s[i] >= '5') {
      pnt = i;
      break;
    }
  }
  if (pnt == -1) {
    cout << s << endl;
    return 0;
  }
  for (int i = pnt - 1; i > 0 and t > 0; i--, t--, pnt--) {
    if (s[i] == '.') {
      flag = false;
      for (int j = i - 1; j >= 0; j--) {
        if (s[j] == '9')
          s[j] = '0';
        else {
          s[j]++, flag = true;
          break;
        }
      }
      if (!flag) cout << 1;
      for (int j = 0; j < i; j++) cout << s[j];
      return 0;
    }
    s[i]++;
    if (s[i] == '5')
      continue;
    else {
      pnt--;
      break;
    }
  }
  for (int i = 0; i <= pnt; i++) {
    cout << s[i];
  }
  return 0;
}
