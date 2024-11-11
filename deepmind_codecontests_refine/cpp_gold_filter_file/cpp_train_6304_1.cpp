#include <bits/stdc++.h>
using namespace std;
string A;
int n, m, p;
void inc(int &i) {
  A[i--] = '0';
  while (i >= 0 && A[i] == '9') A[i--] = '0';
  if (i >= 0)
    A[i]++;
  else {
    A = "1" + A;
    i = p;
    p++;
  }
}
void enter() { cin >> n >> m >> A; }
void solve() {
  p = A.find(".");
  A.erase(A.begin() + p);
  n--;
  int i = p;
  while (i < n && A[i] < '5') ++i;
  while (i >= p && m > 0 && A[i] >= '5') m--, inc(i);
  A = A.substr(0, max(i + 1, p));
  if (p < A.size()) A.insert(A.begin() + p, '.');
  cout << A << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if (ifstream("test.inp")) cin.rdbuf((new ifstream("test.inp"))->rdbuf());
  enter();
  solve();
}
