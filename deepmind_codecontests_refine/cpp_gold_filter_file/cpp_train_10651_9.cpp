#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, s;
  cin >> n;
  int t[n], p[n], g[n], k;
  string a[n];
  for (int i = 0; i < n; i++) {
    cin >> s >> a[i];
    t[i] = 0;
    p[i] = 0;
    g[i] = 0;
    for (int j = 0; j < s; j++) {
      char b, c, d, e, f, x, h, y;
      cin >> b >> c >> d >> e >> f >> x >> h >> y;
      if (b == c && c == e && e == f && f == h && h == y)
        t[i]++;
      else if (b > c && c > e && e > f && f > h && h > y)
        p[i]++;
      else
        g[i]++;
    }
  }
  int* i1;
  i1 = max_element(t, t + n);
  k = 0;
  cout << "If you want to call a taxi, you should call: ";
  for (int i = 0; i < n; i++)
    if (*i1 == t[i]) k++;
  for (int i = 0; i < n; i++) {
    if (*i1 == t[i]) {
      cout << a[i];
      if (k != 1)
        cout << ", ";
      else
        cout << ".";
      k--;
    }
  }
  cout << endl;
  i1 = max_element(p, p + n);
  k = 0;
  cout << "If you want to order a pizza, you should call: ";
  for (int i = 0; i < n; i++)
    if (*i1 == p[i]) k++;
  for (int i = 0; i < n; i++) {
    if (*i1 == p[i]) {
      cout << a[i];
      if (k != 1)
        cout << ", ";
      else
        cout << ".";
      k--;
    }
  }
  cout << endl;
  i1 = max_element(g, g + n);
  k = 0;
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (int i = 0; i < n; i++)
    if (*i1 == g[i]) k++;
  for (int i = 0; i < n; i++) {
    if (*i1 == g[i]) {
      cout << a[i];
      if (k != 1)
        cout << ", ";
      else
        cout << ".";
      k--;
    }
  }
  return 0;
}
