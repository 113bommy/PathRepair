#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int s, d;
  cin >> s >> d;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    if (a > s)
      s = a;
    else
      s = int(ceil((double(s) - a) / b)) * b + a;
    cerr << s << " ";
  }
  cout << s;
  return 0;
}
