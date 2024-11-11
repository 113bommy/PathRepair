#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long A[n];
  long long B[1001] = {0};
  long long maxi = 0;
  long long maxnum = 1;
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
    B[A[i]]++;
    maxi = max(maxi, B[A[i]]);
    maxnum = max(maxnum, A[i]);
  }
  vector<string> v[1001];
  vector<string> ans[1001];
  if (B[1] == 2) {
    ans[0].push_back("0");
    ans[1].push_back("1");
  }
  if (B[1] == 1) {
    v[1].push_back("1");
    ans[1].push_back("0");
  }
  if (B[1] == 0) {
    v[1].push_back("0");
    v[1].push_back("1");
  }
  if (ans[1].size() < B[1]) {
    cout << "NO";
    return 0;
  }
  for (long long i = 2; i < maxnum + 1; i++) {
    for (long long j = 0; j < v[i - 1].size(); j++) {
      if (B[i] > ans[i].size()) {
        ans[i].push_back(v[i - 1][j] + "0");
      } else {
        v[i].push_back(v[i - 1][j] + "0");
      }
      if (B[i] > ans[i].size()) {
        ans[i].push_back(v[i - 1][j] + "1");
      } else {
        v[i].push_back(v[i - 1][j] + "1");
      }
      if (v[i].size() >= maxi) {
        break;
      }
    }
    if (ans[i].size() < B[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  long long ind[1001] = {0};
  for (long long i = 0; i < n; i++) {
    long long a = A[i];
    cout << ans[a][ind[a]] << "\n";
    ind[a]++;
  }
  return 0;
}
