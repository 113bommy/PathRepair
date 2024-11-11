#include <bits/stdc++.h>
using namespace std;
long long dd[25][2200];
long long re[25][2200];
long long ans[2200];
int main() {
  long long n;
  cin >> n;
  memset((dd), (0), sizeof(dd));
  for (long long i = (0); i < (12); ++i) {
    int index = 0;
    int a = 2 << i;
    int b = 1 << i;
    while (1) {
      for (long long j = (0); j < (b); ++j) {
        dd[i * 2][index + j] = 1;
      }
      index += a;
      if (index > 1050) break;
    }
    int index1 = 1 << i;
    int a1 = 2 << i;
    int b1 = 1 << i;
    while (1) {
      for (long long j = (0); j < (b1); ++j) {
        dd[i * 2 + 1][index1 + j] = 1;
      }
      index1 += a1;
      if (index1 > 1050) break;
    }
  }
  for (long long i = (0); i < (2200); ++i) {
    ans[i] = 2000000000;
  }
  int count = 0;
  for (long long i = (0); i < (20); ++i) {
    vector<long long> v;
    for (long long j = (0); j < (n); ++j) {
      if (j + 1 > n) break;
      if (dd[i][j] == 1) v.push_back(j + 1);
    }
    if (v.size() == 0) break;
    count++;
    cout << v.size() << endl;
    for (long long j = (0); j < (v.size()); ++j) {
      cout << v[j];
      if (j != v.size() - 1) cout << " ";
    }
    cout << endl;
    for (long long j = (0); j < (n); ++j) {
      long long a;
      cin >> a;
      re[i][j] = a;
    }
  }
  cout << "-1" << endl;
  for (long long i = (0); i < (n); ++i) {
    for (long long j = (0); j < (count); ++j) {
      if (dd[j][i] == 1) continue;
      ans[i] = min(ans[i], re[j][i]);
    }
    cout << ans[i];
    if (i != n - 1) cout << " ";
  }
  cout << endl;
  return 0;
}
