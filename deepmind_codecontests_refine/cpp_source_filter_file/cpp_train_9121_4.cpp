#include <bits/stdc++.h>
using namespace std;
string f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";
long long lens[100005];
char solve(int n, long long i) {
  if (n == 0) {
    if (i >= (int)(f0).size()) return '.';
    return f0[i];
  }
  assert(n > 0);
  if (i < (int)(a).size()) return a[i];
  i -= (int)(a).size();
  if (lens[n - 1] >= i) return solve(n - 1, i);
  i -= lens[n - 1];
  if (i < (int)(b).size()) return b[i];
  i -= (int)(b).size();
  if (lens[n - 1] >= i) return solve(n - 1, i);
  i -= lens[n - 1];
  if (i < (int)(c).size()) return c[i];
  return '.';
}
void rsolve() {
  int n;
  long long i;
  cin >> n >> i;
  i--;
  cout << solve(n, i);
}
void solve() {
  lens[0] = (int)(f0).size();
  for (int i = 1; i <= 100000; i++) {
    if (lens[i - 1] <= 2e18) {
      lens[i] =
          (int)(a).size() + (int)(b).size() + (int)(c).size() + 2 * lens[i - 1];
    } else {
      lens[i] = 1e18;
    }
  }
  int t;
  cin >> t;
  while (t--) rsolve();
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
