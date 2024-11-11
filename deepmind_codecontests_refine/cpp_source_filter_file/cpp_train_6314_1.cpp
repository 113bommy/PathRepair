#include <bits/stdc++.h>
using namespace std;
long long n;
int func(long long x) {
  if (x % 2 == 1)
    return (x + 1LL) / 2LL;
  else
    return func(x + n - x / 2LL);
}
vector<int> g[200005];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  int q;
  cin >> q;
  while (q--) {
    long long x;
    cin >> x;
    cout << func(x) << endl;
  }
  return 0;
}
