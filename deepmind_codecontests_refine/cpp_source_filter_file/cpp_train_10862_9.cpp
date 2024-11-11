#include <bits/stdc++.h>
using namespace std;
const int L = 1e5 + 7;
struct comp {
  bool operator()(long long x, long long y) { return x > y; }
};
set<long long> pos, neg;
set<long long, comp> curp, curn;
std::map<long long, long long> cn, pn, cp, pp;
int a[L];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long sump = 0, sumn = 0, cop = 0, con = 0, tot = 0, tmp;
  int n, len, k;
  cin >> n >> len;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> k;
  for (int i = 0; i < len; ++i) {
    if (a[i] > 0) {
      pos.insert(a[i]);
      pp[a[i]]++;
    } else if (a[i] < 0) {
      neg.insert(-a[i]);
      pn[-a[i]]++;
    }
    tot += a[i];
  }
  while (cop < k && !(pos.empty())) {
    tmp = *(--pos.end());
    curp.insert(tmp);
    sump += tmp;
    cp[tmp]++;
    cop++;
    pp[tmp]--;
    if (pp[tmp] == 0) pos.erase(pos.begin());
  }
  while (con < k && !(neg.empty())) {
    tmp = *(--neg.end());
    curn.insert(tmp);
    cn[tmp]++;
    con++;
    sumn -= tmp;
    pn[tmp]--;
    if (pn[tmp] == 0) neg.erase(--neg.end());
  }
  long long ans = 0;
  if (tot < 0)
    ans = abs(tot - 2 * sump - 0);
  else
    ans = abs(tot - 2 * sumn - 0);
  for (int i = 1; i < n; ++i) {
    if (i + len - 1 >= n) break;
    if (a[i - 1] > 0) {
      if (curp.find(a[i - 1]) != curp.end()) {
        sump -= a[i - 1];
        cp[a[i - 1]]--;
        cop--;
        if (cp[a[i - 1]] == 0) curp.erase(a[i - 1]);
      } else if (pos.find(a[i - 1]) != pos.end()) {
        pp[a[i - 1]]--;
        if (pp[a[i - 1]] == 0) pos.erase(a[i - 1]);
      }
    } else if (a[i - 1] < 0) {
      if (curn.find(-a[i - 1]) != curn.end()) {
        cn[-a[i - 1]]--;
        if (cn[-a[i - 1]] == 0) curn.erase(-a[i - 1]);
        con--;
        sumn -= a[i - 1];
      } else if (neg.find(-a[i - 1]) != neg.end()) {
        pn[-a[i - 1]]--;
        if (pn[-a[i - 1]] == 0) neg.erase(-a[i - 1]);
      }
    }
    tot -= a[i - 1];
    if (a[i + len - 1] > 0) {
      if (!curp.empty() && a[i + len - 1] > *(--curp.end())) {
        tmp = *(--curp.end());
        cp[tmp]--;
        if (cp[tmp] == 0) curp.erase(--curp.end());
        curp.insert(a[i + len - 1]);
        sump -= tmp;
        sump += a[i + len - 1];
        cp[a[i + len - 1]]++;
        pp[tmp]++;
        pos.insert(tmp);
      } else {
        pp[a[i + len - 1]]++;
        pos.insert(a[i + len - 1]);
      }
    } else if (a[i + len - 1] < 0) {
      if (!curn.empty() && -a[i + len - 1] > *(--curn.end())) {
        tmp = *(--curn.end());
        cn[tmp]--;
        if (cn[tmp] == 0) curn.erase(--curn.end());
        curn.insert(-a[i + len - 1]);
        cn[-a[i + len - 1]]++;
        sumn += tmp;
        sumn += a[i + len - 1];
        pn[tmp]++;
        neg.insert(tmp);
      } else {
        pn[-a[i + len - 1]]++;
        neg.insert(-a[i + len - 1]);
      }
    }
    while (cop < k && !pos.empty()) {
      tmp = *(--pos.end());
      sump += tmp;
      pp[tmp]--;
      if (pp[tmp] == 0) pos.erase(--pos.end());
      cp[tmp]++;
      curp.insert(tmp);
      cop++;
    }
    while (con < k && !(neg.empty())) {
      tmp = *(--neg.end());
      sumn -= tmp;
      pn[tmp]--;
      if (pn[tmp] == 0) neg.erase(--neg.end());
      cn[tmp]++;
      con++;
      curn.insert(tmp);
    }
    tot += a[i + len - 1];
    ans = max(ans, max(abs(tot - 2 * sump), abs(tot - 2 * sumn)));
  }
  cout << ans;
  return 0;
}
