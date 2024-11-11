#include <bits/stdc++.h>
using namespace std;
bool myCmp(pair<int, int> &p1, pair<int, int> &p2) {
  return p1.first > p2.first;
}
unsigned long long choose(unsigned long long n, unsigned long long k) {
  if (k > n) {
    return 0;
  }
  unsigned long long r = 1;
  for (unsigned long long d = 1; d <= k; ++d) {
    r *= n--;
    r /= d;
  }
  return r;
}
const int MAXN = 10e5;
int arr[MAXN] = {0};
set<int> soso;
long long ans = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    soso.insert(arr[i]);
  }
  sort(arr, arr + n, greater<int>());
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (soso.count(arr[i]) && arr[i] % k == 0 && soso.count(arr[i] / k))
      soso.erase(arr[i] / k);
  }
  cout << soso.size() << endl;
  return 0;
}
