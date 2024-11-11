#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n + 1];
  arr[n] = 0;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    if (arr[i] >= arr[i + 1]) v.push_back(arr[i]);
  }
  cout << v.size() << "\n";
  for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}
