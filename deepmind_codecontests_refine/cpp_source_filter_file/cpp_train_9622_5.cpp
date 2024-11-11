#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  c_p_c();
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> v1;
  for (int i = 0; i <= n - 1; i++) cin >> v[i];
  int k = 1;
  for (int i = 0; i <= n - 1; i++) {
    if (v[i] > 0 && v[i] == k) {
      v1.push_back(20001 + i);
      k++;
    }
  }
  cout << v1.size();
  cout << endl;
  for (auto x : v1) {
    cout << x << " ";
  }
  return 0;
}
