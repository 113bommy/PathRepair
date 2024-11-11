#include <bits/stdc++.h>
const double PI = acos(-1);
const double EPS = 1e-12;
const int MOD = 1e9 + 7;
const int INF = 1 << 30;
using namespace std;
int main() {
  string data;
  int len, in;
  bool cnt[30], fl = false;
  cin >> in >> data;
  queue<int> q;
  len = data.length();
  for (int i = 1; i <= in; i += 1) {
    cnt[i] = false;
  }
  if (len >= 2 * in - 1) {
    for (int i = 0; i <= (len - 1) / 2; i += 1) {
      if (data[i] >= 'a' && data[i] <= 'z') {
        if (data[len - i - 1] >= 'a' && data[len - i - 1] <= 'z') {
          if (data[i] != data[len - i - 1]) {
            cout << "IMPOSSIBLE" << endl;
            fl = true;
            break;
          } else
            cnt[data[i] - 'a' + 1] = true;
        } else {
          data[len - i - 1] = data[i];
          cnt[data[i] - 'a' + 1] = true;
        }
      } else if (data[len - i - 1] >= 'a' && data[len - i - 1] <= 'z') {
        if (data[i] == '?') {
          data[i] = data[len - i - 1];
          cnt[data[i] - 'a' + 1] = true;
        } else {
          fl = true;
          cout << "IMPOSSIBLE" << endl;
          break;
        }
      }
    }
    if (!fl) {
      for (int i = 1; i <= in; i += 1) {
        if (!cnt[i]) q.push(i);
      }
      for (int i = (len - 1) / 2; i >= 0; i--) {
        if (data[i] == data[len - i - 1] && data[i] == '?') {
          if (q.empty()) {
            data[i] = 'a';
            data[len - i - 1] = 'a';
          } else {
            data[i] = 'a' + q.front() - 1;
            data[len - i - 1] = data[i];
            q.pop();
          }
        }
      }
      if (!q.empty()) {
        cout << "IMPOSSIBLE" << endl;
      } else
        cout << data << endl;
    }
  } else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}
