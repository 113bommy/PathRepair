#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[100100], b[100100];
long long dp[100100];
long long pos[100100];
long long rr[100100];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  long long mx = -1;
  long long id = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] > mx) {
      mx = b[i];
      id = i;
    }
  }
  int k = 0;
  for (int i = id; k < n; k++) {
    a[k] = b[i];
    pos[k] = i;
    i++;
    if (i >= n) i = 0;
  }
  int j = n;
  set<pair<long long, long long> > f;
  for (int i = 1; i < n; i++) {
    if (a[i] * 2 < a[0]) {
      j = i;
      break;
    }
    f.insert({a[i], i});
  }
  if (j == n) {
    for (int i = 0; i < n; i++) {
      cout << -1 << " ";
    }
    cout << endl;
    return 0;
  }
  dp[0] = j;
  bool flip = false;
  for (int i = n - 1; i > 0; i--) {
    long long nnext = i + 1;
    if (nnext >= n) nnext = 0;
    if (a[i] > a[nnext]) {
      while (f.size() != 0) {
        long long mmin = (*(f.begin())).second;
        if (mmin * 2 < a[i]) {
          j--;
          if (j < 0) {
            flip = true;
            j = n - 1;
          }
          f.erase(make_pair(a[j], j));
        } else {
          break;
        }
      }
      if (!flip) {
        dp[i] = (n - i) + j;
      } else
        dp[i] = (j - i);
    } else {
      dp[i] = dp[nnext] + 1;
    }
    f.insert({a[i], i});
  }
  for (int i = 0; i < n; i++) {
    rr[pos[i]] = dp[i];
  }
  for (int i = 0; i < n; i++) {
    cout << rr[i] << " ";
  }
  cout << endl;
  return 0;
}
