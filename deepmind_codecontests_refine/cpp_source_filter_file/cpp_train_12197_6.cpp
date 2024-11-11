#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long t;
bool check(long long k) {
  for (int i = 5; i < k; i++) {
    if (k % i == 0) {
      t = i;
      return true;
    }
  }
  return false;
}
int main() {
  long long k;
  cin >> k;
  vector<char> v = {'a', 'e', 'i', 'o', 'u'};
  if (k < 25) {
    cout << -1 << endl;
    return 0;
  }
  if (check(k)) {
    long long x = t;
    long long y = k / t;
    for (int i = 0; i < y; i++) {
      for (int j = 0; j < x; j++) {
        cout << v[(i + j) % 5];
      }
    }
    cout << endl;
  } else
    cout << -1 << endl;
  return 0;
}
