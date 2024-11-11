#include <bits/stdc++.h>
using namespace std;
void swagWaalaFunction() {
  long long int n, k;
  cin >> n >> k;
  auto query = [&](long long int l, long long int r, string type) {
    long long int x;
    cout << type << " " << l << " " << r << endl;
    cin >> x;
    return x;
  };
  vector<long long int> v(n + 1);
  long long int x = query(1, 2, "and") + query(1, 2, "or");
  long long int y = query(2, 3, "and") + query(2, 3, "or");
  long long int z = query(1, 3, "and") + query(1, 3, "or");
  v[0] = (x + z - y) / 2;
  v[1] = (x + y - z) / 2;
  v[2] = (y + z - x) / 2;
  for (long long int i = 4; i <= n; i++) {
    long long int sum = query(i - 1, i, "and") + query(i - 1, i, "or");
    v[i] = sum - v[i - 1];
  }
  sort(1 + v.begin(), v.end());
  cout << "finish " << v[k] << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tc = 1;
  for (int i = 0; i < tc; i++) {
    swagWaalaFunction();
  }
  return 0;
}
