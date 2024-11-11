#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
vector<pair<int, int> > vc;
int main() {
  int n, a;
  cin >> n >> a;
  if (a & 1)
    cout << (a + 1) / 2;
  else
    cout << (n - a) / 2;
  return 0;
}
