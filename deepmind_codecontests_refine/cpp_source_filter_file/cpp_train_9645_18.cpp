#include <bits/stdc++.h>
using namespace std;
int y, c = 1;
vector<int> a;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> y;
    a.push_back(y);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i + 1] > a[i] && a[i] != 0) {
      c++;
    }
  }
  cout << c;
  return 0;
}
