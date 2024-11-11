#include <bits/stdc++.h>
using namespace std;
struct myComp {
  bool operator()(pair<long long, long long> const &a,
                  pair<long long, long long> const &b) {
    if (a.second == b.second)
      return a.first > b.first;
    else
      return a.second < b.second;
  }
};
bool mycomp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return b.first < a.first;
}
struct comp {
  bool operator()(vector<long long> &a, vector<long long> &b) const {
    return a.size() < b.size();
  }
};
bool comps(pair<long long, long long> &a, pair<long long, long long> &b) {
  return a.second < b.second;
}
void prints(vector<long long> &v) {
  for (auto &it : v) cout << it << " ";
  cout << endl;
}
long long solve(vector<long long> &v, long long i, long long n) {
  long long j = i;
  if (i >= n) {
    return 0;
  }
  for (j = i + 1; j < n - 1; j++) {
    if (v[i] == v[j]) {
      long long temp = v[j];
      long long temp2 = v[i + 1];
      for (long long k = i + 1; k <= j; k++) {
        temp2 = v[k];
        v[k] = temp;
        temp = temp2;
      }
      break;
    }
  }
  return (j - i - 1 + solve(v, i + 2, n));
}
void print(vector<long long> &v) {
  for (auto &it : v) {
    cout << it << " ";
  }
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  test = 1;
  while (test--) {
    long long n;
    cin >> n;
    vector<long long> v(2 * n);
    for (long long i = 0; i < 2 * n; i++) {
      cin >> v.at(i);
    }
    cout << solve(v, 0, 2 * n) << endl;
  }
  return 0;
}
