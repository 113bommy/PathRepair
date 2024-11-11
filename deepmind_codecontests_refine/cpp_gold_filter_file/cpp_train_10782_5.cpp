#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n, h = 0;
  long long int s = 0;
  string str;
  vector<int> u, p, k;
  cin >> a >> b >> c >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    getline(cin, str);
    if (str[1] == 'U')
      u.push_back(x);
    else
      p.push_back(x);
  }
  sort(u.begin(), u.end());
  sort(p.begin(), p.end());
  for (int i = 0; i < min(a, (int)u.size()); i++) {
    h++;
    s += u[i];
  }
  for (int i = 0; i < min(b, (int)p.size()); i++) {
    h++;
    s += p[i];
  }
  for (int i = a; i < u.size(); i++) k.push_back(u[i]);
  for (int i = b; i < p.size(); i++) {
    k.push_back(p[i]);
  }
  sort(k.begin(), k.end());
  for (int i = 0; i < min(c, (int)k.size()); i++) {
    h++;
    s += k[i];
  }
  cout << h << " " << s;
  return 0;
}
