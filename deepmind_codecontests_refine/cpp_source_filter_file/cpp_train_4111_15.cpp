#include <bits/stdc++.h>
using namespace std;
int vv[300300];
int maxI[300300];
int minI[300300];
long long conta2(int n, int mid, int pode) {
  ;
  for (int i = 0; i < n; i++)
    ;
  ;
  maxI[mid + 1] = minI[mid + 1] = vv[mid + 1];
  for (int i = mid + 2; i < n; i++) {
    maxI[i] = max(maxI[i - 1], vv[i]);
    minI[i] = min(minI[i - 1], vv[i]);
  }
  int pma = mid + 1;
  int pmi = mid + 1;
  int maxcur = vv[mid];
  int mincur = vv[mid];
  long long ret = 0;
  vector<pair<int, int> > tira;
  vector<pair<int, int> > soma;
  for (int i = mid - 1; i >= 0; i--) {
    mincur = min(mincur, vv[i]);
    maxcur = max(maxcur, vv[i]);
    while (pma < n && maxI[pma + 1] < maxcur) pma++;
    while (pmi < n && minI[pmi] > mincur) pmi++;
    if (maxcur == vv[mid] && !pode) continue;
    int len = maxcur - mincur + 1;
    int fim = i + len - 1;
    ;
    ;
    if (pmi > pma || fim < pmi || fim > pma)
      if (fim > mid && fim < n && maxI[fim] <= maxcur && minI[fim] >= mincur) {
        ;
        ret++;
      }
    if (pma >= pmi && pmi != n) {
      int u = maxcur + i;
      ;
      if (pmi + 1 > mid) tira.push_back(pair<int, int>(pmi - 1, u));
      soma.push_back(pair<int, int>(pma, u));
    }
  }
  map<int, int> mp;
  sort(tira.begin(), tira.end());
  sort(soma.begin(), soma.end());
  int ptira = 0;
  int psoma = 0;
  for (int i = mid + 1; i <= n; i++) {
    if (i != n)
      ;
    if (i != n) mp[i + minI[i]]++;
    while (ptira < tira.size() && tira[ptira].first == i) {
      ret -= mp[tira[ptira].second];
      ptira++;
    }
    while (psoma < soma.size() && soma[psoma].first == i) {
      ret += mp[soma[psoma].second];
      psoma++;
    }
  };
  return ret;
}
int v[300300];
long long conta(int a, int b) {
  if (a == b) return 1;
  if (b == a + 1) {
    if (abs(v[b] - v[a]) == 1) return 3;
    return 2;
  };
  int mid = (a + b) / 2;
  long long ret = conta(a, mid);
  ret += conta(mid, b) - 1;
  for (int i = a; i <= b; i++) vv[i - a] = v[i];
  long long u = 0;
  u += conta2(b - a + 1, mid - a, 1);
  int l = vv[mid - a];
  for (int i = 0; i < b - a + 1; i++)
    ;
  reverse(vv, vv + b - a + 1);
  long long uu = conta2(b - a + 1, (b - a + 1) / 2, 0);
  assert(vv[(b - a + 1) / 2] == l);
  ;
  ;
  return ret + u + uu;
}
long long brute(int n) {
  long long ret = 0;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      int ma = 0, mi = n;
      for (int k = i; k <= j; k++) ma = max(ma, v[k]), mi = min(mi, v[k]);
      if (ma - mi == j - i) ret++;
    }
  return ret;
}
int main() {
  int n;
  srand(time(0));
  while (0) {
    n = 7;
    for (int i = 0; i < n; i++) v[i] = i;
    random_shuffle(v, v + n);
    ;
    for (int i = 0; i < n; i++)
      ;
    long long A = brute(n), B = conta(0, n - 1);
    ;
    assert(A == B);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b), a--, b--;
    v[a] = b;
  }
  cout << conta(0, n - 1) << endl;
}
