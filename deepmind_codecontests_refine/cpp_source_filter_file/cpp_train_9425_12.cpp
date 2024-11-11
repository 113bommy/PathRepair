#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E5 + 5;
const int BASE1 = 1E9 + 7;
const int BASE2 = 999999993;
int n, k;
bool mark[MAXN];
int a[MAXN], nTurn;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i <= n; ++i) {
    string s;
    cin >> s;
    if (s[0] == '?')
      mark[i] = 1, ++nTurn;
    else {
      stringstream ss;
      ss << s;
      ss >> a[i];
    }
  }
  if (k == 0) {
    if (!mark[0]) {
      if (a[0] == 0) {
        cout << "Yes";
      } else {
        cout << "No";
      }
      return 0;
    } else {
      if (nTurn % 2 == 1) {
        cout << "Yes";
      } else {
        cout << "No";
      }
      return 0;
    }
  } else {
    if (nTurn == 0) {
      long long res1 = 0, res2 = 0, cur1 = 1, cur2 = 1;
      for (int i = 0; i <= n; ++i) {
        res1 = (res1 + a[i] * cur1 % BASE1 + BASE1) % BASE1;
        res2 = (res2 + a[i] * cur2 % BASE2 + BASE2) % BASE2;
        cur1 = cur1 * k % BASE1;
        cur2 = cur2 * k % BASE2;
      }
      if (res1 == 0 && res2 == 0) {
        cout << "Yes";
      } else
        cout << "No";
    } else {
      if (n % 2 == 0) {
        cout << "No";
      } else {
        cout << "Yes";
      }
    }
  }
}
