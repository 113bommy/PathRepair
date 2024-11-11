#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5;
const long long int mod = 1e9 + 7;
const long double E = 2.71828;
const long double PI = 3.14159265;
vector<long long int> v[3];
long long int arr[N];
long long int n;
void ans(long long int x, long long int y) {
  bool nonzero = 0;
  for (long long int i = 1; i < n + 1; i++) {
    if (i == x or i == y) {
      continue;
    }
    if (!arr[i] and !nonzero) {
      continue;
    }
    if (arr[i]) {
      nonzero = 1;
    }
    cout << arr[i];
  }
  if (!nonzero) {
    cout << "0\n";
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  bool flag = 0;
  long long int sum = 0;
  for (long long int i = 1; i < n + 1; i++) {
    cin >> arr[i];
    sum += arr[i];
    if (!arr[i]) {
      flag = 1;
    }
  }
  sort(arr + 1, arr + n + 1);
  if (arr[0] != 0) {
    cout << "-1\n";
    return 0;
  }
  reverse(arr + 1, arr + n + 1);
  for (long long int i = 1; i < n + 1; i++) {
    v[arr[i] % 3].push_back(i);
  }
  if (sum % 3 == 0) {
    ans(-1, -1);
  }
  if (sum % 3 == 1) {
    if (v[1].size() > 0) {
      ans(v[1][v[1].size() - 1], -1);
    } else {
      ans(v[2][v[2].size() - 1], v[2][v[2].size() - 2]);
    }
  }
  if (sum % 3 == 2) {
    if (v[2].size() > 0) {
      ans(v[2][v[2].size() - 1], -1);
    } else {
      ans(v[1][v[1].size() - 1], v[1][v[1].size() - 2]);
    }
  }
  return 0;
}
