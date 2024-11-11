#include <bits/stdc++.h>
using namespace std;
int a[205000];
int b[205000];
int cost[205000];
vector<pair<int, int> > pa;
vector<pair<int, int> > pb;
vector<pair<int, int> > pc;
vector<pair<int, int> > pd;
long long suma[205000];
long long sumb[205000];
long long sumc[205000];
long long sumd[205000];
long long ans;
long long acnt;
long long bcnt;
long long dcnt;
long long val(char id, int pos) {
  if (id == 'a') return suma[pos] - suma[pos - 1];
  if (id == 'b') return sumb[pos] - sumb[pos - 1];
  if (id == 'c') return sumc[pos] - sumc[pos - 1];
  if (id == 'd') return sumd[pos] - sumd[pos - 1];
}
int add() {
  if (acnt < pa.size() && bcnt < pb.size() && dcnt < pd.size()) {
    if (val('a', acnt + 1) <= min(val('b', bcnt + 1), val('d', dcnt + 1)))
      acnt++;
    else if (val('b', bcnt + 1) <= min(val('a', acnt + 1), val('d', dcnt + 1)))
      bcnt++;
    else if (val('d', dcnt + 1) <= min(val('a', acnt + 1), val('b', bcnt + 1)))
      dcnt++;
  } else if (acnt < pa.size() && bcnt < pb.size()) {
    if (val('a', acnt + 1) <= val('b', bcnt + 1))
      acnt++;
    else
      bcnt++;
  } else if (bcnt < pb.size() && dcnt < pd.size()) {
    if (val('b', bcnt + 1) <= val('d', dcnt + 1))
      bcnt++;
    else
      dcnt++;
  } else if (acnt < pa.size() && dcnt < pd.size()) {
    if (val('a', acnt + 1) <= val('d', dcnt + 1))
      acnt++;
    else
      dcnt++;
  } else if (acnt < pa.size())
    acnt++;
  else if (bcnt < pb.size())
    bcnt++;
  else if (dcnt < pd.size())
    dcnt++;
  else
    return -1;
  return 0;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1); i <= (n); i++) {
    scanf("%d%d%d", cost + i, a + i, b + i);
    if (a[i] == 1 && b[i] == 1)
      pc.push_back({cost[i], i});
    else if (a[i] == 1)
      pa.push_back({cost[i], i});
    else if (b[i] == 1)
      pb.push_back({cost[i], i});
    else
      pd.push_back({cost[i], i});
  }
  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());
  sort(pc.begin(), pc.end());
  sort(pd.begin(), pd.end());
  for (int i = 1; i <= (int)pa.size(); i++)
    suma[i] = suma[i - 1] + pa[i - 1].first;
  for (int i = 1; i <= (int)pb.size(); i++)
    sumb[i] = sumb[i - 1] + pb[i - 1].first;
  for (int i = 1; i <= (int)pc.size(); i++)
    sumc[i] = sumc[i - 1] + pc[i - 1].first;
  for (int i = 1; i <= (int)pd.size(); i++)
    sumd[i] = sumd[i - 1] + pd[i - 1].first;
  if (min(pa.size(), pb.size()) + pc.size() < k) {
    cout << "-1" << endl;
    return 0;
  }
  ans = min((int)pc.size(), k);
  acnt = max(k - ans, 0ll);
  bcnt = max(k - ans, 0ll);
  dcnt = 0;
  if (acnt + bcnt + ans > m) {
    cout << "-1" << endl;
    return 0;
  }
  while (acnt + bcnt + dcnt + ans < m) {
    if (add() == -1) {
      cout << "-1" << endl;
      return 0;
    }
  }
  long long cmp = sumc[ans] + suma[acnt] + sumb[bcnt] + sumd[dcnt];
  int cur = ans - 1;
  int alim = acnt;
  int blim = bcnt;
  int dlim = dcnt;
  while (cur >= 0) {
    if (acnt + cur < k && bcnt + cur < k) {
      long long del = 2ll * k - acnt - bcnt - 2ll * cur;
      if (dcnt + 1 <= del) break;
      while (dcnt && acnt + cur < k && acnt < pa.size()) {
        acnt++, dcnt--;
      }
      while (dcnt && bcnt + cur < k && bcnt < pb.size()) {
        bcnt++, dcnt--;
      }
    }
    if (acnt + cur == k - 1)
      acnt++;
    else if (bcnt + cur == k - 1)
      bcnt++;
    else {
      if (add() == -1) break;
    }
    if (pa.size() < acnt || pb.size() < bcnt || pd.size() < dcnt) break;
    long long now = sumc[cur] + suma[acnt] + sumb[bcnt] + sumd[dcnt];
    if (now < cmp) {
      cmp = now;
      alim = acnt;
      blim = bcnt;
      dlim = dcnt;
      ans = cur;
    }
    cur--;
  }
  cout << cmp << endl;
  for (int i = 0; i < alim; i++) printf("%d ", pa[i].second);
  for (int i = 0; i < blim; i++) printf("%d ", pb[i].second);
  for (int i = 0; i < dlim; i++) printf("%d ", pd[i].second);
  for (int i = 0; i < ans; i++) printf("%d ", pc[i].second);
}
