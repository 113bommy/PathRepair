#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
long long mod = 1000000007;
vector<long long> gr[200001];
vector<long long> grev[200001];
long long a[200005];
long long b[200005];
void solve() {
  vector<string> s(6);
  for (long long i = int(0); i < int(6); i++) cin >> s[i];
  sort(s.begin(), s.end());
  vector<string> ans;
  do {
    string a = s[0], b = s[1], c = s[2], d = s[3], e = s[4], f = s[5];
    long long A = ((int)a.length()), B = ((int)b.length()),
              C = ((int)c.length()), D = ((int)d.length()),
              E = ((int)e.length()), F = ((int)f.length());
    long long V = C;
    long long H = D;
    bool ok = true;
    vector<string> temp(H, string(V, '.'));
    auto go = [&](string sos, long long row, long long col, bool is_hor) {
      for (long long i = int(0); i < int(((int)sos.length())); i++) {
        if (row < H && col < V) {
          if (temp[row][col] != '.' && temp[row][col] != sos[i]) {
            ok = false;
          } else {
            temp[row][col] = sos[i];
          }
        } else {
          ok = false;
        }
        if (is_hor)
          col++;
        else
          row++;
      }
    };
    go(a, 0, 0, true);
    go(b, 0, 0, false);
    go(d, 0, A - 1, false);
    go(c, B - 1, 0, true);
    go(e, D - 1, A - 1, true);
    go(f, B - 1, C - 1, false);
    if (A + E == C + 1 && B + F == D + 1) {
    } else {
      ok = false;
    }
    if (!ok) continue;
    if (ans.empty() || ans > temp) {
      ans = temp;
    }
  } while (next_permutation(s.begin(), s.end()));
  if (ans.empty()) {
    cout << "Impossible"
         << "\n";
  } else {
    for (string x : ans) cout << x << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
