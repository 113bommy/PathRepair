#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  map<int, int> mp;
  for (int i = a; i <= b; i++) mp[i]++;
  n = n - 1;
  while (n--) {
    int x, y;
    cin >> x >> y;
    for (int i = x; i < y; i++) mp[i] = 0;
  }
  int count = 0;
  for (auto x : mp) {
    if (x.second != 0) count++;
  }
  cout << count << endl;
}
