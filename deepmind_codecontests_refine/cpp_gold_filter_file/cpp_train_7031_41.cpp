#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, md, b, k;
  cin >> md;
  cin >> k;
  md = min(md, k);
  cin >> k;
  md = min(md, k);
  cin >> k;
  md = min(md, k);
  cin >> a >> b;
  cout << max(0, min(b + 1, md) - a);
}
