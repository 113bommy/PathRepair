#include <bits/stdc++.h>
using namespace std;
vector<int> f[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 1e5; i++) {
    for (int j = i; j <= 1e5; j += i) f[j].push_back(i);
  }
  while (n--) {
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> g;
    for (int i : f[A]) g.push_back(i);
    for (int i : f[B]) g.push_back(i);
    for (int i : f[C]) g.push_back(i);
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, h = 0;
    for (int i = 0; i < g.size(); i++) {
      if (A % g[i] == 0 && B % g[i] != 0 && C % g[i] != 0) a++;
      if (A % g[i] != 0 && B % g[i] == 0 && C % g[i] != 0) b++;
      if (A % g[i] == 0 && B % g[i] == 0 && C % g[i] != 0) c++;
      if (A % g[i] != 0 && B % g[i] != 0 && C % g[i] == 0) d++;
      if (A % g[i] == 0 && B % g[i] != 0 && C % g[i] == 0) e++;
      if (A % g[i] != 0 && B % g[i] != 0 && C % g[i] == 0) f++;
      if (A % g[i] == 0 && B % g[i] == 0 && C % g[i] == 0) h++;
    }
    int res = 0;
    res += a * b * (d + e + f + h);
    res += a * c * (d + e + f + h);
    res += a * d * (f + h);
    res += a * e * (f + h);
    res += a * f * (f + 1) / 2 + a * f * h + a * h * (h + 1) / 2;
    res += b * c * (d + e + f + h);
    res += b * d * (f + h);
    res += b * e * (e + 1) / 2 + b * e * (f + h);
    res += b * f * h;
    res += b * h * (h + 1) / 2;
    res += c * (c + 1) / 2 * (d + e + f + h);
    res += c * d * (e + f + h);
    res += c * e * (e + 1) / 2 + c * e * (f + h);
    res += c * f * (f + 1) / 2 + c * f * h;
    res += c * h * (h + 1) / 2;
    res += d * e * (f + h);
    res += d * f * h + d * h * (h + 1) / 2;
    res += e * (e + 1) / 2 * (f + h);
    res += e * f * (f + 1) / 2 + e * f * h;
    res += e * h * (h + 1) / 2;
    res += f * (f + 1) * h / 2;
    res += f * (h + 1) * h / 2;
    res += h + (h - 1) * h + (h - 1) * (h - 2) * h / 6;
    cout << res << endl;
  }
}
