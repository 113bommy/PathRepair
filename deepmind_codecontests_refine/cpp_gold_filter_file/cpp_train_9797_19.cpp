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
  int k;
  cin >> n >> k;
  int p = k;
  int x = (k * 2) + 1;
  vector<int> v;
  for (int i = 1; i <= n; i += x) {
    v.push_back(i);
  }
  int xx = v[v.size() - 1];
  int tot = 0;
  if (n - xx > p) {
    tot = n - xx - p;
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] + tot << " ";
  cout << endl;
  return 0;
}
