#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> v(3);
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> k;
    v[i % 3] += k;
  }
  long long ans = max_element(v.begin(), v.end()) - v.begin();
  if (ans == 0) cout << "chest";
  if (ans == 1) cout << "biseps";
  if (ans == 2) cout << "back";
  return 0;
}
