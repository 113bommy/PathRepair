#include <bits/stdc++.h>
using namespace std;
void solve() {
  string inp;
  cin >> inp;
  long long int nn = inp.size();
  vector<long long int> out;
  for (long long int i = 0; i < nn; i++) {
    long long int t = 0, w = 0, o = 0, n = 0, e = 0;
    if (inp[i] == 't') {
      vector<long long int> pos(3);
      t = 1;
      long long int j = i + 1;
      for (; j < nn; j++) {
        if (inp[j] != 't')
          break;
        else
          t++;
      }
      for (; j < nn; j++)
        if (inp[j] != 'w')
          break;
        else
          w++, pos[0] = j;
      for (; j < nn; j++)
        if (inp[j] != 'o')
          break;
        else
          o++, pos[1] = j;
      for (; j < nn; j++)
        if (inp[j] != 'n')
          break;
        else
          n++, pos[2] = j;
      for (; j < nn; j++)
        if (inp[j] != 'e')
          break;
        else
          e++;
      if (t > 0 && e > 0 && w == 1 && o == 1 && n == 1)
        out.push_back(pos[1]);
      else if (w > 1 || w == 0 || t == 0 || o == 0) {
        if (n > 1 || n == 0 || o == 0 || e == 0) {
          ;
        } else {
          out.push_back(pos[2]);
        }
      } else if (n > 1 || n == 0 || o == 0 || e == 0) {
        out.push_back(pos[0]);
      } else {
        out.push_back(pos[0]);
        out.push_back(pos[2]);
      }
      i += (t + w + o + n + e - 1);
    } else if (inp[i] == 'o') {
      vector<long long int> pos(3);
      o = 1;
      long long int j = i + 1;
      for (; j < nn; j++)
        if (inp[j] != 'o')
          break;
        else
          o++, pos[1] = j;
      for (; j < nn; j++)
        if (inp[j] != 'n')
          break;
        else
          n++, pos[2] = j;
      for (; j < nn; j++)
        if (inp[j] != 'e')
          break;
        else
          e++;
      if (o > 0 && n == 1 && e > 0) out.push_back(pos[2]);
      i += (o + n + e - 1);
    }
  }
  cout << out.size() << endl;
  for (auto x : out) cout << x + 1 << " ";
  cout << endl;
}
signed main() {
  long long int t;
  cin >> t;
  while (t--) solve();
}
