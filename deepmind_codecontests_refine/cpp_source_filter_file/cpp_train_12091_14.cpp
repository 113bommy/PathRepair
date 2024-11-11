#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k, temp, ele, ele1;
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    a.push_back(temp);
  }
  if (a.size() >= 2) {
    sort(a.begin(), a.end(), greater<long long>());
    ele = a[0];
    ele1 = a[1];
    long long ans = 0;
    ans = ceil(m / (k + 1)) * (ele * k + ele1) + (m % (k + 1)) * ele;
    cout << ans;
    return 0;
  } else {
    cout << a[0] * (min(m, k));
  }
  return 0;
}
