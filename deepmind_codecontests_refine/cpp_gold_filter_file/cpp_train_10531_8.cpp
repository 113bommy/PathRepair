#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x;
  cin >> n >> x;
  long long arr[(1 << 18)];
  vector<long long> v;
  v.push_back(0);
  arr[0] = 1;
  for (long long i = 1; i < (1 << 18); i++) arr[i] = 0;
  for (long long i = 1; i < (1 << n); i++) {
    if (arr[i ^ x]) continue;
    v.push_back(i);
    arr[i] = 1;
  }
  cout << v.size() - 1 << "\n";
  for (int i = 1; i < v.size(); i++) {
    cout << (v[i] ^ v[i - 1]) << " ";
  }
  return 0;
}
