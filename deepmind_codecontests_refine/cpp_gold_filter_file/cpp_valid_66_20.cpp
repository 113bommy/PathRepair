#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> p;
  int i = 1;
  while (p.size() <= 1000) {
    if (i % 3 != 0 && i % 10 != 3) p.push_back(i);
    i++;
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> i;
    cout << p[i - 1] << '\n';
  }
}
