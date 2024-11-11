#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const double INF = 1e12, EPS = 1e-9;
void run() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cout << (i ? n : i) << (i == n - 1 ? "\n" : " ");
}
int main() { run(); }
