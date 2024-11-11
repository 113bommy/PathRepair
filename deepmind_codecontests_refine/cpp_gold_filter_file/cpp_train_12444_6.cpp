#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;
int main() {
  ios::sync_with_stdio(false);
  string s;
  vector<int> op, f;
  int n, oNeg = 0, oPos = 1;
  op.push_back(1);
  do {
    cin >> s;
    if (s == "+") {
      oPos++;
      op.push_back(1);
    } else if (s == "-") {
      oNeg++;
      op.push_back(-1);
    }
  } while (s != "=");
  cin >> n;
  if (oPos * n - n < oNeg || oPos - n - oNeg * n > 0)
    cout << "Impossible\n";
  else {
    cout << "Possible\n";
    long long sPos, sNeg;
    if (oNeg < oPos) {
      sNeg = oNeg * n;
      sPos = sNeg + n;
    } else if (oNeg == oPos) {
      sNeg = oNeg * n - n;
      sPos = sNeg + n;
    } else {
      sPos = oPos * n;
      sNeg = sPos - n;
    }
    for (int i = 0; i < op.size(); i++) {
      if (op[i] == 1) {
        if (sPos == oPos) {
          f.push_back(1);
          sPos--;
          oPos--;
          continue;
        }
        if (sPos - (oPos - 1) < n) {
          f.push_back(sPos - (oPos - 1));
          sPos = oPos - 1;
          oPos--;
        } else {
          f.push_back(n);
          sPos -= n;
          oPos--;
        }
      } else {
        if (sNeg == oNeg) {
          f.push_back(1);
          sNeg--;
          oNeg--;
          continue;
        }
        if (sNeg - (oNeg - 1) < n) {
          f.push_back(sNeg - (oNeg - 1));
          sNeg = oNeg - 1;
          oNeg--;
        } else {
          f.push_back(n);
          sNeg -= n;
          oNeg--;
        }
      }
    }
    cout << f[0];
    for (int i = 1; i < f.size(); i++)
      cout << " " << (op[i] == 1 ? "+" : "-") << " " << f[i];
    cout << " = " << n;
  }
  return 0;
}
