#include <bits/stdc++.h>
using namespace std;
int _set(int N, int pos) { return N = N | (1 << pos); }
int _reset(int N, int pos) { return N = N & ~(1 << pos); }
bool _check(int N, int pos) { return (bool)(N & (1 << pos)); }
bool _upper(char a) { return a >= 'A' && a <= 'Z'; }
bool _lower(char a) { return a >= 'a' && a <= 'z'; }
bool _digit(char a) { return a >= '0' && a <= '9'; }
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  vector<int> A, B;
  int n;
  for (long long i = 1; i <= 70000; i++) {
    if (i * (i + 1) / 2 <= a + b) n = i;
  }
  for (int i = n; i; i--) {
    if (i <= a)
      A.push_back(i), a -= i;
    else if (i <= b)
      B.push_back(i), b -= i;
  }
  cout << A.size() << '\n';
  for (auto i : A) cout << i << ' ';
  cout << '\n';
  cout << B.size() << '\n';
  for (auto i : B) cout << i << ' ';
  return 0;
}
