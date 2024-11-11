#include <bits/stdc++.h>
int dx4[] = {0, 0, -1, 1};
int dy4[] = {-1, 1, 0, 0};
bool valid(int r, int c, int x, int y) {
  if (x >= 1 && x <= r && y >= 1 && y <= c) return 1;
  return 0;
}
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char a[1000];
  for (int i = 0; i < n; i++) {
    a[i + 1] = s[i];
  }
  int x;
  int cnt = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    x = 1;
    cnt = 0;
    for (int j = i + 1; j <= i + i && j <= n; j++) {
      if (a[j] == a[x]) cnt++;
      x++;
    }
    if (cnt == i) v.push_back(cnt);
  }
  if (v.size() == 0)
    cout << n << endl;
  else {
    cout << n - v[v.size() - 1] + 1 << endl;
  }
  return 0;
}
