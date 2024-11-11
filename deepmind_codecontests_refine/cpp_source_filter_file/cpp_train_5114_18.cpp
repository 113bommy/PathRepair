#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> vec;
  for (int i = 1; i < n; i++) {
    if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) vec.push_back(i + 1);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) {
    if ((i + 1) < vec.size() && vec[i + 1] - vec[i] == 2) {
      i++;
      cnt++;
    } else
      cnt++;
  }
  cout << cnt << endl;
}
