#include <bits/stdc++.h>
using namespace std;
long long power(long x, long n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  long n2 = n / 2;
  long long po = power(x, n2);
  if (n % 2) return po * po * x;
  return po * po;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
class CSoldierAndCards {
  queue<int> v1, v2;
  int n, win;
  map<string, set<string>> M;

 public:
  int dfs() {
    if (v1.size() == 0) {
      win = 2;
      return 0;
    }
    if (v2.size() == 0) {
      win = -1;
      return 0;
    }
    string s1 = "", s2 = "";
    queue<int> q;
    q = v1;
    while (!q.empty()) {
      s1 += ('0' + q.front());
      q.pop();
    }
    q = v2;
    while (!q.empty()) {
      s2 += +('0' + q.front());
      q.pop();
    }
    if (M[s1].find(s2) != M[s1].end()) {
      win = -1;
      return 0;
    }
    M[s1].insert(s2);
    int x = v1.front(), y = v2.front();
    v1.pop();
    v2.pop();
    if (x > y) {
      v1.push(y);
      v1.push(x);
    } else {
      v2.push(x);
      v2.push(y);
    }
    return 1 + dfs();
  }
  void solve(std::istream &cin, std::ostream &cout) {
    cin >> n;
    int k, i, x;
    cin >> k;
    for (i = 0; i < k; i++) cin >> x, v1.push(x);
    cin >> k;
    for (i = 0; i < k; i++) cin >> x, v2.push(x);
    int moves = dfs();
    if (win > 0)
      cout << moves << " " << win << '\n';
    else
      cout << win << '\n';
  }
};
int main() {
  CSoldierAndCards solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);
  return 0;
}
