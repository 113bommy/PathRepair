#include <bits/stdc++.h>
using namespace std;
long long int a[600009], c[600009], d[600009];
map<int, int> b;
int main() {
  long long int n, l;
  cin >> n >> l;
  long long int p = 8 * l / n, o;
  o = p;
  p = pow(2, p);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  if (o >= 16 || p >= b.size())
    cout << 0 << endl;
  else {
    long long int ans = 1, maxx = 0, minn = 0x3f3f3f3f;
    for (map<int, int>::iterator i = b.begin(); i != b.end(); i++) {
      c[ans] = i->second;
      d[ans] = d[ans - 1] + c[ans];
      ans++;
      maxx += c[ans - 1];
    }
    for (int i = 1; i < ans; i++) {
      if (i + p - 1 >= ans) break;
      minn = min(minn, maxx - (d[i + p - 1] - d[i - 1]));
    }
    cout << minn << endl;
  }
}
