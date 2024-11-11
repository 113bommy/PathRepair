#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void die(int x, int y) {
  cout << x << " " << y;
  exit(0);
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 1; i < n; ++i)
    if (s[i] == s[i - 1])
      die(i, i + 1);
    else if (i - 2 >= 0 && s[i - 2] == s[i])
      die(i - 1, i + 1);
  cout << "-1 -1";
}