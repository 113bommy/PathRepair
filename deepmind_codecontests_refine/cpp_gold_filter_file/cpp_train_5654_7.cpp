#include <bits/stdc++.h>
using namespace std;
int n, a, b, x, y, z, sum;
vector<int> v;
int main() {
  cin >> n >> a >> b;
  v.push_back(1);
  x = 1;
  n--;
  if (!a && !b)
    for (int i = 0; i < n + 1; i++) cout << 1 << " ";
  if (!a && !b) return 0;
  if (b == 0) {
    v.clear();
    v.push_back(3);
    v.push_back(2);
    n--;
    x = 3;
  }
  if (a + b > n) {
    cout << -1;
    return 0;
  }
  while (b--) {
    x += v[v.size() - 1];
    v.push_back(x);
    n--;
  }
  while (a--) {
    x++;
    v.push_back(x);
    n--;
  }
  while (n--) v.push_back(1);
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}
