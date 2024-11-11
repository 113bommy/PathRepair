#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, t, temp;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < p; ++i) {
    cin >> temp;
    a[temp - 1] = 1;
  }
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> temp;
    a[temp - 1] = 1;
  }
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == 0) {
      cout << "Oh, my keyboard!";
      return 0;
    }
  }
  cout << "I become the guy.";
  return 0;
}
