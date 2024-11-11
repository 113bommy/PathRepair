#include <bits/stdc++.h>
using namespace std;
string a[103];
int ans;
vector<int> V;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  bool test = false;
  while (test == false) {
    test = true;
    ans++;
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1].find(a[i]) != std::string::npos)
        continue;
      else {
        swap(a[i + 1], a[i]);
        test = false;
      }
    }
    if (ans > n * n) return cout << "NO", 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << a[i] << endl;
  return 0;
}
