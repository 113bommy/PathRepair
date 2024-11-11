#include <bits/stdc++.h>
using namespace std;
void Solution() {
  int n, k;
  cin >> n >> k;
  int a[n];
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (5 - a[i] >= k) {
      v.push_back(a[i]);
    }
  }
  cout << v.size() / 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solution();
  return 0;
}
