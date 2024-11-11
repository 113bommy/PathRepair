#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> v(20000);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  long long s = 0;
  for (int i = 1; i < n; i++) s += (v[i].size() * (v[i].size() - 1)) / 2;
  cout << s;
  return 0;
}
