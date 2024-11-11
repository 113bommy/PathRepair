#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  int s = 0, z = 0;
  for (int i = (max(0, n - 82)); i < (n); i++) {
    int temp = i;
    s = 0;
    while (temp != 0) {
      s += temp % 10;
      temp /= 10;
    }
    if (s + i == n) {
      a.push_back(i);
      z++;
    }
  }
  cout << z << endl;
  for (auto i = a.begin(); i != a.end(); ++i) {
    cout << *i;
    cout << '\n';
  }
}
