#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, mem;
  cin >> n >> mem;
  mem = mem * 8;
  set<long long> s;
  map<long long, long long> m;
  long long* arr = new long long[n];
  for (long long i = 0; i < n; ++i) {
    cin >> arr[i];
    ++m[arr[i]];
    s.insert(arr[i]);
  }
  double dif = (double)s.size();
  long long num = ceil(log2(dif));
  if (num * n <= mem) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  long long logval = mem / n;
  long long difval = pow(2, logval);
  vector<long long> v;
  map<long long, long long>::iterator it = m.begin();
  while (it != m.end()) {
    v.push_back(it->second);
    ++it;
  }
  long long tot = 0;
  long long curwin = 0;
  for (long long i = 0; i < v.size(); ++i) {
    if (i < difval) {
      curwin += v[i];
    }
    tot += v[i];
  }
  ans = tot - curwin;
  for (long long i = 1; i < v.size(); ++i) {
    if (i + difval - 1 >= v.size()) {
      break;
    }
    curwin -= v[i - 1];
    curwin += v[i + difval - 1];
    ans = min(ans, tot - curwin);
  }
  cout << ans << endl;
}
