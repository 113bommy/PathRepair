#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
const int INF = 1000000000;
const long long INFL = 1000000000000000LL;
const int MAXN = 200;
const double EPS = 1e-10;
pair<int, int> ar[MAXN];
int n, kk;
priority_queue<int, vector<int>, greater<int> > dalem;
priority_queue<int> luar;
int main() {
  scanf("%d%d", &n, &kk);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ar[i].first);
    ar[i].second = i;
  }
  sort(ar, ar + n);
  int maks = -INF;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      vector<int> dalem, luar;
      int jumlah = 0;
      for (int k = 0; k < n; k++) {
        if (ar[k].second < i || ar[k].second > j)
          luar.push_back(ar[k].first);
        else
          dalem.push_back(ar[k].first), jumlah += ar[k].first;
      }
      int SL = (int)luar.size();
      int SD = (int)dalem.size();
      int now = SL - 1;
      int awal = 0;
      int cou = 0;
      while (awal < SD && now > 0 && cou < kk && dalem[awal] < luar[now]) {
        jumlah += luar[now] - dalem[awal];
        awal++;
        now--;
        cou++;
      }
      maks = max(maks, jumlah);
    }
  }
  printf("%d\n", maks);
  return 0;
}
