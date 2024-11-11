#include <bits/stdc++.h>
using namespace std;
template <typename T>
void printvec(vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  int i = 0, j = 0;
  int ttt = 0;
  cin >> ttt;
  while (ttt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++) {
      cin >> a[i];
    };
    sort(a.begin(), a.end());
    int m = n / 2;
    for (i = 1; i <= m; i++) {
      cout << a[i] << " " << a[0] << '\n';
    }
  }
  return 0;
}
