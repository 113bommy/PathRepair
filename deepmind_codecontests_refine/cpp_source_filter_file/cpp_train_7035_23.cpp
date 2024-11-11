#include <bits/stdc++.h>
using namespace std;
long long n, i, j, k, l, low, mid, high, d[200005];
string a, b, c;
bool check(long long mid) {
  c = a;
  long long flag = 0;
  for (i = 0; i < mid; i++) c[d[i] - 1] = '0';
  for (i = 0; i < a.size(); i++) {
    if (c[i] == b[flag]) {
      flag++;
    }
    if (flag == b.size()) return true;
  }
  return false;
}
int main() {
  cin >> a >> b;
  for (i = 0; i < a.size(); i++) {
    cin >> d[i];
  }
  c = a;
  low = 0;
  high = a.size() - 1;
  mid = (low + high) / 2;
  while (high - low > 1) {
    if (check(mid))
      low = mid;
    else
      high = mid;
    mid = (low + high) / 2;
  }
  cout << mid;
  return 0;
}
