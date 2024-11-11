#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int MAX = 500000;
double eps = 1e-9;
const long long BIG_INF = 7000000000000000000LL;
const int INF = 2000000000;
double PI = 3.1415926535897932384626433832795;
string inttostring(int n) {
  stringstream a;
  a << n;
  string A;
  a >> A;
  return A;
}
int stringtoint(string A) {
  stringstream a;
  a << A;
  int p;
  a >> p;
  return p;
}
int main() {
  int n;
  cin >> n;
  int a;
  deque<int> D;
  for (int i = 0; i < n; i++) {
    cin >> a;
    D.push_back(a);
  }
  int f, maxb = 0, cnt = 0, bits = 0;
  while (!D.empty()) {
    f = D.front();
    cnt = 0;
    while (!D.empty() && f == D.front()) {
      cnt++;
      D.pop_front();
    }
    bits += (cnt % 2);
    maxb = max(maxb, f + 1);
    while (cnt >= 2) {
      D.push_front(f + 1);
      cnt -= 2;
    }
  }
  cout << maxb - bits << "\n";
}
