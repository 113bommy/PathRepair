#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      v.push_back(a);
    }
    long long start = 0;
    long long end = v.size() - 1;
    while (start < v.size()) {
      if (start != v[start] - 1) {
        break;
      }
      start++;
    }
    while (end >= 0) {
      if (end != v[end] - 1) {
        break;
      }
      end--;
    }
    long long count = 0;
    if (start > end) {
      cout << 0 << endl;
    } else {
      for (long long i = start; i <= end; i++) {
        if (v[i] - 1 != i) count++;
      }
      if (count == 0)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
