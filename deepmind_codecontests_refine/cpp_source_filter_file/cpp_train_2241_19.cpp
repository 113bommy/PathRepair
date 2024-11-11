#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string lts(long long int x) {
  stringstream second;
  second << x;
  return second.str();
}
long long int stl(string x) {
  stringstream second(x);
  long long int temp;
  second >> temp;
  return temp;
}
string cts(char x) {
  string second(1, x);
  return second;
}
const int MOD = 1e9 + 7;
const int N = 30;
int A[N];
char ans[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  for (long long int i = (0); i <= (long long int)(n - 1); ++i) {
    cin >> A[i];
  }
  bool t = d % 2;
  int ch = 0;
  memset(ans, '.', sizeof(ans));
  for (long long int i = (d); i >= (long long int)(1); --i) {
    if (t) {
      for (long long int j = (a + c); j >= (long long int)(a + 1); --j) {
        --A[ch];
        ans[i][j] = ch + 'a';
        if (A[ch] == 0) ++ch;
      }
    } else {
      for (long long int j = (a + 1); j <= (long long int)(a + c); ++j) {
        --A[ch];
        ans[i][j] = ch + 'a';
        if (A[ch] == 0) ++ch;
      }
    }
    t = !t;
  }
  t = 1;
  for (long long int i = (1); i <= (long long int)(b); ++i) {
    if (t) {
      for (long long int j = (a); j >= (long long int)(1); --j) {
        --A[ch];
        ans[i][j] = ch + 'a';
        if (A[ch] == 0) ++ch;
      }
    } else {
      for (long long int j = (1); j <= (long long int)(a); ++j) {
        --A[ch];
        ans[i][j] = ch + 'a';
        if (A[ch] == 0) ++ch;
      }
    }
    t = !t;
  }
  cout << "YES\n";
  for (long long int i = (1); i <= (long long int)(max(b, d)); ++i) {
    for (long long int j = (1); j <= (long long int)(a + c); ++j) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}
