#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long d1, d2, d3;
  cin >> d1 >> d2 >> d3;
  long long mn = 0, sum = 0, ans = 0, cnt = 0, ser = 0;
  sum = d1 + d1 + d2 + d2;
  ans = d1 + d2 + d3;
  cnt = d2 + d3 + d3 + d2;
  ser = d1 + d3 + d3 + d1;
  mn = min(min(min(sum, ans), cnt), ser);
  cout << mn << "\n";
}
