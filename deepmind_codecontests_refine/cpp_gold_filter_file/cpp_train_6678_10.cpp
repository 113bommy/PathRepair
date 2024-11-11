#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  long long count[200001] = {0};
  long long m = 0;
  long long hf = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    count[a[i]]++;
    m = max(count[a[i]], m);
    if (count[a[i]] == m) {
      hf = a[i];
    }
  }
  vector<long long> p;
  for (long long i = 0; i < n; i++) {
    if (a[i] == hf) {
      p.push_back(i);
    }
  }
  long long last = -1;
  cout << n - m << endl;
  for (long long i = 0; i < p.size(); i++) {
    if (p[i] == 0) {
      last = p[i];
      continue;
    }
    if (p[i] == last + 1) {
      last = p[i];
      continue;
    }
    for (long long j = p[i] - 1; j > last; j--) {
      if (a[j] < hf) {
        cout << 1 << " " << j + 1 << " " << j + 2 << endl;
      } else {
        cout << 2 << " " << j + 1 << " " << j + 2 << endl;
      }
    }
    last = p[i];
  }
  if (p[p.size() - 1] != n - 1) {
    for (long long j = p[p.size() - 1] + 1; j < n; j++) {
      if (a[j] < hf) {
        cout << 1 << " " << j + 1 << " " << j << endl;
      } else {
        cout << 2 << " " << j + 1 << " " << j << endl;
      }
    }
  }
}
