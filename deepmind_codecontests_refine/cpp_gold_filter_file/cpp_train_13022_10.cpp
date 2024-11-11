#include <bits/stdc++.h>
using namespace std;
int mp[105];
int main(int argc, const char* argv[]) {
  int n, m;
  int a, b;
  cin >> n >> m;
  int min_ = 500;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    min_ = min(min_, min(a, b));
    for (int j = a; j <= b; j++) {
      mp[j]++;
    }
  }
  int count = 0;
  vector<int> v;
  for (int i = 1; i <= m; i++) {
    if (mp[i] == 0) {
      count++;
      v.push_back(i);
    }
  }
  cout << count << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}
