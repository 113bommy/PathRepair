#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vp;
vector<int> d;
int countt[200005], countSum[200005];
int trck[209], trck2[209][200005];
int main() {
  int i, j, k, l, temp, t, n, m, ans, caseno = 0;
  while (cin >> n) {
    vp.clear();
    memset(countt, 0, sizeof(countt));
    memset(trck, 0, sizeof(trck));
    memset(trck2, 0, sizeof(trck2));
    memset(countSum, 0, sizeof(countSum));
    for (i = 0; i < n; i++) {
      cin >> temp;
      vp.push_back(make_pair(temp, 0));
      countt[temp]++;
    }
    for (i = 0; i < n; i++) {
      cin >> temp;
      vp[i].second = temp;
      countSum[vp[i].first] += temp;
      trck[temp]++;
      trck2[temp][vp[i].first]++;
    }
    sort(vp.begin(), vp.end());
    ans = 2000000009;
    int lost = 0;
    for (i = n - 1; i >= 0; i -= countt[vp[i].first]) {
      j = countt[vp[i].first];
      int needed = i + 1 - (j * 2 - 1);
      k = 1;
      temp = lost;
      while (needed > 0 && k < 201) {
        m = trck[k] - trck2[k][vp[i].first];
        m = min(needed, m);
        temp += m * k;
        needed -= m;
        trck[k] -= trck2[k][vp[i].first];
        k++;
      }
      while (k < 201) {
        trck[k] -= m + trck2[k][vp[i].first];
        k++;
      }
      lost += countSum[vp[i].first];
      ans = min(ans, temp);
    }
    cout << ans << endl;
  }
  return 0;
}
