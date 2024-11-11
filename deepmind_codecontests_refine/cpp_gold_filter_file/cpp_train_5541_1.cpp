#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int inf = 1010101010;
const double PI = 4 * atan(1);
struct myLT {
  bool operator()(pair<string, int> const& a, pair<string, int> const& b) {
    if (a.second > b.second) return true;
    if (a.second < b.second) return false;
    return a.first < b.first;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  map<string, int> cnt;
  vector<int> val(n);
  for (int i = 0; i < (n); i++) cin >> val[i];
  for (int i = 0; i < (m); i++) {
    string s;
    cin >> s;
    cnt[s]++;
  }
  set<pair<string, int>, myLT> se(cnt.begin(), cnt.end());
  int mi = 0;
  sort(val.begin(), val.end(), less<int>());
  int k = 0;
  for (typeof((se).begin()) it = (se).begin(); it != (se).end(); ++it) {
    mi += (*it).second * val[k];
    k++;
  }
  int mx = 0;
  sort(val.begin(), val.end(), greater<int>());
  k = 0;
  for (typeof((se).begin()) it = (se).begin(); it != (se).end(); ++it) {
    mx += (*it).second * val[k];
    k++;
  }
  cout << mi << " " << mx << endl;
}
