#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  vector<int> v, p;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(a);
    p.push_back(b);
  }
  int price = p[0];
  for (int i = 0; i < n; i++) {
    price = min(price, p[i]);
    sum = sum + (v[i] * price);
  }
  cout << sum;
}
