#include <bits/stdc++.h>
using namespace std;
const long long int N = 100001;
const long long int M = 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int _ = 1;
  while (_--) {
    long long int n, m, ans = 0, x = 0, y = 0, k, b, a;
    cin >> n >> m >> k;
    x = 4 * n * m - 2 * n - 2 * m;
    string moves[] = {"RDU", "L", "D"};
    vector<string> sol;
    string s;
    if (k > x) {
      cout << "NO\n";
    } else {
      a = n;
      b = m;
      cout << "YES\n";
      n--;
      while (k > 0 && n > 0) {
        if (k > 0 && m > 1) {
          x = min(k / 3, m - 1);
          if (x) {
            s = to_string(x) + " " + moves[0];
            sol.push_back(s);
          }
          y = m - 1;
          while (k > 0 && x > 0 && y > 0) {
            k -= 3;
            y--;
            x--;
          }
          if (y > 0) {
            if (k == 1) {
              s = "1 R";
              sol.push_back(s);
              k--;
            }
            if (k == 2) {
              s = "1 RD";
              sol.push_back(s);
              k -= 2;
            }
          }
        }
        if (k > 0 && m > 1) {
          x = min(k, m - 1);
          s = to_string(x) + " " + moves[1];
          sol.push_back(s);
          y = m - 1;
          while (k > 0 && y > 0) {
            k--;
            y--;
          }
        }
        if (k > 0 && n > 0) {
          k--;
          s = "1 " + moves[2];
          sol.push_back(s);
        }
        n--;
      }
      if (k > 0) {
        x = min(k, m - 1);
        s = to_string(x) + " R";
        k -= x;
        sol.push_back(s);
        if (k > 0) {
          x = min(k, m - 1);
          s = to_string(x) + " L";
          sol.push_back(s);
          k -= x;
        }
      }
      if (k > 0) {
        x = min(a - 1, k);
        s = to_string(x) + " U";
        sol.push_back(s);
      }
      cout << sol.size() << "\n";
      for (auto i : sol) cout << i << "\n";
    }
  }
  return 0;
}
