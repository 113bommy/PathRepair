#include <bits/stdc++.h>
using namespace std;
vector<long long> v1;
vector<long long> v2;
long long n, m;
void init(long long arr[]) {
  long long n1 = n / 2;
  long long blast = pow(2, n1);
  long long index, yo, sum;
  for (long long i = 0; i < blast; i++) {
    yo = i;
    index = 0;
    sum = 0;
    while (yo > 0) {
      if (yo & 1 != 0) {
        sum += arr[index];
      }
      yo = yo >> 1;
      index++;
    }
    v1.push_back(sum % m);
  }
  blast = pow(2, n - n1);
  for (long long i = 0; i < blast; i++) {
    yo = i;
    index = n1;
    sum = 0;
    while (yo > 0) {
      if (yo & 1 != 0) {
        sum += arr[index];
      }
      yo = yo >> 1;
      index++;
    }
    v2.push_back(sum % m);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
}
int main() {
  cin >> n >> m;
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i] %= m;
  }
  init(arr);
  long long ans = 0;
  long long a, b;
  n = v1.size();
  for (long long i = 0; i < n; i++) {
    a = v1[i] + v2.back();
    a %= m;
    b = lower_bound(v2.begin(), v2.end(), m - v1[i]) - v2.begin();
    b--;
    if (b < 0)
      b = 0;
    else {
      b = v1[i] + v2[b];
    }
    b %= m;
    ans = max(ans, max(a, b));
  }
  cout << ans << endl;
}
