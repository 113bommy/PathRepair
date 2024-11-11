#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n';
  err(++it, args...);
}
const int NMAX = 100005;
int n, k, a, b, len;
char s[NMAX];
int main() {
  int i;
  char C, D;
  cin.sync_with_stdio(false);
  cin >> n >> k >> a >> b;
  C = 'G';
  D = 'B';
  if (a > b) {
    swap(a, b);
    swap(C, D);
  }
  if (b > 1LL * (a + 1) * k) {
    cout << "NO\n";
    return 0;
  }
  int last = 0;
  for (i = 1; i <= n; i++) {
    if (b >= a && last < k) {
      last++;
      b--;
      s[++len] = D;
    } else {
      a--;
      s[++len] = C;
      last = 0;
    }
  }
  cout << (s + 1) << "\n";
  return 0;
}
