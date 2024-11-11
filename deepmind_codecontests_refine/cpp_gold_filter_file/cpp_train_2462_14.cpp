#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> v[], int s, int H, int h[]) {
  h[s] = H;
  for (vector<int>::iterator it = v[s].begin(); it != v[s].end(); it++) {
    dfs(v, *it, H + 1, h);
  }
}
int main() {
  int n, s, H;
  cin >> n;
  int c[n - 1];
  vector<int> v[n];
  int h[n], height[n];
  for (int i = 0; i < n; i++) {
    h[i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n - 1; i++) {
    v[c[i] - 1].push_back(i + 1);
  }
  s = 0;
  H = 0;
  dfs(v, s, H, h);
  for (int i = 0; i < n; i++) {
    height[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    height[h[i]]++;
  }
  s = 0;
  for (int i = 0; i < n; i++) {
    s += (height[i] % 2);
  }
  cout << s;
  return 0;
}
