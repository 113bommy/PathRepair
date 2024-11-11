#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n];
  long long brr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = 0; i < n; i++) cin >> brr[i];
  map<long long, long long> mp;
  vector<long long> v;
  for (long long i = 0; i < n; i++) mp[arr[i]]++;
  for (auto i : mp) {
    if (i.second >= 2) {
      v.push_back(i.first);
    }
  }
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    long long f = 0;
    for (long long j = 0; j < v.size(); j++) {
      if ((arr[i] & v[j]) == arr[i]) f = 1;
    }
    if (f) sum += brr[i];
  }
  cout << sum << endl;
}
