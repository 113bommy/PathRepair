#include <bits/stdc++.h>
using namespace std;
map<long long, long long> ps;
void addone(long long tmp) {
  ps[tmp]++;
  if (ps[tmp] == 2) {
    ps[tmp] = 0;
    addone(tmp + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long tmp;
    cin >> tmp;
    addone(tmp);
  }
  long long mx = 1, cnt = 0;
  for (map<long long, long long>::iterator it = ps.begin(); it != ps.end();
       it++) {
    if (it->second) {
      mx = max(it->first, mx);
      cnt++;
    }
  }
  cout << (mx + 1) - cnt << endl;
}
