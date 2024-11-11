#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
long long area(int a, int b, int c) {
  cout << "1 " << a << " " << b << " " << c << endl;
  long long res;
  scanf("%lld", &res);
  return res;
}
bool cw(int a, int b, int c) {
  cout << "2 " << a << " " << b << " " << c << endl;
  int res;
  scanf("%d", &res);
  return res > 0;
}
void print(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) printf("%d ", a[i]);
}
int n;
vector<int> up, down, a, b, c, d;
vector<pair<long long, int>> x;
int main() {
  cin >> n;
  for (int i = 3; i <= n; i++)
    if (cw(1, 2, i))
      down.push_back(i);
    else
      up.push_back(i);
  for (int i = 0; i < up.size(); i++)
    x.push_back(make_pair(area(1, 2, up[i]), up[i]));
  sort(x.begin(), x.end());
  reverse(x.begin(), x.end());
  for (int i = 0; i < x.size(); i++)
    if (i == 0 || !cw(1, x[0].second, x[i].second))
      a.push_back(x[i].second);
    else
      b.push_back(x[i].second);
  a.push_back(1);
  reverse(a.begin(), a.end());
  x.clear();
  for (int i = 0; i < down.size(); i++)
    x.push_back(make_pair(area(2, 1, down[i]), down[i]));
  sort(x.begin(), x.end());
  reverse(x.begin(), x.end());
  for (int i = 0; i < x.size(); i++)
    if (i == 0 || !cw(2, x[0].second, x[i].second))
      c.push_back(x[i].second);
    else
      d.push_back(x[i].second);
  c.push_back(2);
  reverse(c.begin(), c.end());
  cout << 0 << " ";
  print(a);
  print(b);
  print(c);
  print(d);
  cout << endl;
  return 0;
}
