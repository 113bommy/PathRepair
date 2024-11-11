#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> v(n + 1);
  for (int i = 1; i <= n; i++) {
    v[i] = 0;
  }
  long long i = 1, j = 2;
  if (n == 1) {
    cout << 1 << "\n";
    return 0;
  }
  map<long long, long long> m;
  while (j <= n) {
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    long long fms, smf;
    cin >> fms;
    cout << "? " << j << " " << i << "\n";
    cout.flush();
    cin >> smf;
    if (fms > smf) {
      cout.flush();
      v[i] = fms;
      m[v[i]] = 1;
      i = j;
      j++;
    } else {
      v[j] = smf;
      m[v[j]] = 1;
      j++;
    }
  }
  long long miss;
  for (int k = 1; k <= n; k++) {
    if (m[k] == 0) {
      miss = k;
      break;
    }
  }
  for (int k = 1; k <= n; k++) {
    if (v[k] == 0) {
      v[k] = miss;
      break;
    }
  }
  cout << "! ";
  for (int k = 1; k <= n; k++) {
    cout << v[k] << " ";
  }
  cout << "\n";
  return 0;
}
