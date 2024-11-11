#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, m, sum = 0;
  string s;
  vector<string> str;
  vector<long long> cost;
  vector<string> main_message;
  map<string, long long> maping1;
  long long cst;
  cin >> n >> k >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> s;
    str.push_back(s);
  }
  for (long long i = 1; i <= n; i++) {
    cin >> cst;
    cost.push_back(cst);
  }
  for (long long i = 0; i < n; i++) {
    maping1[str[i]] = cost[i];
  }
  long long x, pos;
  for (long long i = 1; i <= k; i++) {
    cin >> x;
    long long xval;
    if (x == 1)
      cin >> xval;
    else {
      long long mini = 1000000;
      long long val[100005];
      for (long long j = 0; j < x; j++) {
        cin >> val[j];
        if (cost[val[j] - 1] < mini) {
          mini = cost[val[j] - 1];
        }
      }
      for (long long j = 0; j < x; j++) {
        maping1[str[val[j] - 1]] = mini;
      }
    }
  }
  string s2;
  for (long long i = 1; i <= m; i++) {
    cin >> s2;
    sum += maping1[s2];
  }
  cout << sum;
  return 0;
}
