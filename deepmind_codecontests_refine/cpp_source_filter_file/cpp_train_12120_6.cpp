#include <bits/stdc++.h>
using namespace std;
long calc1[20000], calc2[2000];
long t, n, k, iter, m, bp;
vector<pair<long, long> > v1, v2, av;
long ans;
long tc;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    calc1[t]++;
    calc2[t]++;
  }
  for (iter = 1; iter <= n; iter++) {
    v1.clear();
    v2.clear();
    for (int i = 1; i <= k; i++) {
      v1.push_back(make_pair(calc1[i], i));
      v2.push_back(make_pair(calc2[i], i));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    tc = v1[v1.size() - 1].second;
    bp = -1;
    for (int j = 0; j < v2.size(); j++)
      if (v2[j].second != tc && v2[j].first > 0) bp = j;
    if (bp == -1) {
      av.push_back(
          make_pair(v1[v1.size() - 1].second, v1[v1.size() - 1].second));
      calc1[v1[v1.size() - 1].second]--;
      calc2[v1[v1.size() - 1].second]--;
    } else {
      av.push_back(make_pair(v1[v1.size() - 1].second, v2[bp].second));
      ++ans;
      calc1[v1[v1.size() - 1].second]--;
      calc2[v2[bp].second]--;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < av.size(); i++)
    cout << av[i].first << " " << av[i].second << endl;
  cin.get();
  cin.get();
  return 0;
}
