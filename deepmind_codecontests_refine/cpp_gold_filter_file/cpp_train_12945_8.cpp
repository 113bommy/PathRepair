#include <bits/stdc++.h>
using namespace std;
string a, x, it;
long ans;
int main() {
  cin >> a;
  it = a[0];
  for (int i = 0; i < a.size(); i++) {
    x = a[i];
    if (x == it) ans++;
    if (x > it) ans = 1, it = x;
  }
  for (int i = 0; i < ans; i++) cout << it;
}
