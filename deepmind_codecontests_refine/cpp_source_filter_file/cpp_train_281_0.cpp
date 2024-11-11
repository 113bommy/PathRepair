#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long> ar;
  long long n, k;
  cin >> n >> k;
  long long i;
  for (i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ar.push_back(x);
  }
  sort(ar.begin(), ar.end());
  long long n1 = ar.size() - 2;
  long long n2, cnt = 0;
  for (n2 = ar.size() - 1; n2 >= 0; n2--) {
    if (n1 == n2) n1--;
    while (n1 >= 0 && ar[n2] - ar[n1] <= k && ar[n1] != ar[n2]) {
      n1--;
      cnt++;
    }
  }
  cout << n - cnt;
}
