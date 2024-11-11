#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, M, i;
  cin >> n >> M;
  int t[n];
  for (i = 0; i < n; i++) {
    cin >> t[i];
  }
  long sum = 0, j, fail = 0;
  vector<unsigned long long> v;
  for (i = 0; i < n; i++) {
    sum = t[i];
    fail = 0;
    for (j = 0; j < i; j++) {
      v.push_back(t[j]);
    }
    sort(v.begin(), v.end());
    for (j = 0; j < i; j++) {
      if (sum + v[j] > M) {
        fail++;
      } else {
        sum += v[j];
      }
    }
    cout << fail << " ";
    v.clear();
  }
}
