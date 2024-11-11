#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  float k;
  cin >> n >> k;
  int cr = 2 * n;
  int cg = 5 * n;
  int cb = 8 * n;
  cout << (int)(ceil((float)cr / k) + ceil((float)cg / k) + ceil((float)cb / k))
       << endl;
}
