#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  for (auto &e : b) cin >> e;
  int r = b.front() + b.back();
  for (int i = 0; i + 1 < n - 1; i++) r += min(b[i], b[i + 1]);
  cout << r << endl;
}
