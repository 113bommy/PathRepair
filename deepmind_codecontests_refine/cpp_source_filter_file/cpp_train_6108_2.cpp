#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int blah[m];
  for (int i = 0; i < m; i++) {
    cin >> blah[i];
  }
  bool check[m + 100];
  memset(check, false, sizeof(check));
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    int x = arr[i];
    for (int j = 0; j < m; j++) {
      if (x == blah[j] && check[j] == false) {
        check[j] = 1;
        v.push_back(x);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << ' ';
  }
  cout << endl;
}
