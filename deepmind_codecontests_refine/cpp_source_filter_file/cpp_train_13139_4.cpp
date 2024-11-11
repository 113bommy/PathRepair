#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
vector<long long> invi(long long n) {
  long long x;
  vector<long long> a;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  return a;
}
vector<bool> prime;
void checkPrime(long long n) {
  for (long long i = 0; i < n + 1; i++) {
    prime.push_back(true);
  }
  prime[0] = false;
  prime[1] = false;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
void solve() {
  long long n, q;
  cin >> n >> q;
  vector<vector<long long>> mat(3, vector<long long>(n + 1, 0));
  long long block = 0;
  for (long long i = 0; i < q; i++) {
    long long x, y;
    cin >> x >> y;
    mat[x][y] = !mat[x][y];
    if (x == 1) {
      x = 2;
    } else {
      x = 1;
    }
    if (mat[x == 1 ? 2 : 1][y]) {
      if (mat[x][y - 1]) {
        block++;
      }
      if (mat[x][y]) {
        block++;
      }
      if (mat[x][y + 1]) {
        block++;
      }
    } else {
      if (mat[x][y - 1]) {
        block--;
      }
      if (mat[x][y]) {
        block--;
      }
      if (mat[x][y + 1]) {
        block--;
      }
    }
    if (block) {
      cout << "No"
           << "\n";
    } else {
      cout << "Yes"
           << "\n";
    }
  }
}
