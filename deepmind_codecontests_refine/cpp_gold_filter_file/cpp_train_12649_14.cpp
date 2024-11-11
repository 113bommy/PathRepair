#include <bits/stdc++.h>
using namespace std;
int d[200005];
vector<int> vec;
int main() {
  int n;
  scanf("%d", &n);
  for (int x, i = 0; i < n; i++) {
    scanf("%d", &x);
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end());
  if (vec.size() == 2) {
    cout << vec.back() - vec.front();
    return 0;
  }
  int step = (n - 2) >> 1;
  int m = n - step - 1;
  int mn = 2e9;
  for (int i = 0; i <= step; i++) {
    int l = vec[i + m] - vec[i];
    mn = min(mn, l);
  }
  cout << mn;
}
