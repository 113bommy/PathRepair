#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, p;
  cin >> n >> p;
  vector<int> app(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    app[i] = (s == "half") ? 1 : 0;
  }
  int am = 0;
  long long sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (app[i] == 1)
      am = am * 2;
    else
      am = am * 2 + 1;
    sum += (long long)p * ((float)am / 2);
  }
  cout << sum << endl;
  return 0;
}
