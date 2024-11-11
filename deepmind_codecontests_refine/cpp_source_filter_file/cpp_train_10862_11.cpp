#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m;
    b /= 2;
    a = ((a % m) * (a % m)) % m;
  }
  return ans % m;
}
set<pair<long long, long long> > neg;
set<pair<long long, long long> > pos;
long long sump, sumn;
long long n, len, k;
long long a[200006];
long long revsp, revsn;
set<pair<long long, long long> > revp, revn, hp, hn;
long long process() {
  long long temp1 = sump, temp2 = sumn;
  sump -= revsp;
  temp2 -= revsp;
  sumn -= revsn;
  temp1 -= revsn;
  long long ans = max(abs(temp2 + sump), abs(temp1 + sumn));
  sump += revsp;
  sumn += revsn;
  return ans;
}
void erase(int st) {
  if (a[st] > 0) {
    pos.erase(make_pair(-a[st], st));
    sump -= a[st];
    if (revp.find(make_pair(-a[st], st)) != revp.end()) {
      revp.erase(make_pair(-a[st], st));
      revsp -= a[st];
      if (hp.size() > 0) {
        revp.insert(*hp.begin());
        revsp -= (*hp.begin()).first;
        hp.erase(*hp.begin());
      }
    } else {
      hp.erase(make_pair(-a[st], st));
    }
  } else if (a[st] < 0) {
    neg.erase(make_pair(a[st], st));
    sumn -= a[st];
    if (revn.find(make_pair(a[st], st)) != revn.end()) {
      revn.erase(make_pair(a[st], st));
      revsn -= a[st];
      if (hn.size() > 0) {
        revn.insert(*hn.begin());
        revsn += (*hn.begin()).first;
        hn.erase(*hn.begin());
      }
    } else {
      hn.erase(make_pair(a[st], st));
    }
  }
}
void add(int i) {
  if (a[i] > 0) {
    pos.insert(make_pair(-a[i], i));
    sump += a[i];
    if (revp.size() < k) {
      revp.insert(make_pair(-a[i], i));
      revsp += a[i];
    } else {
      pair<long long, long long> val = *(revp.rbegin());
      if ((-val.first) < a[i]) {
        revp.erase(make_pair(val.first, val.second));
        revp.insert(make_pair(-a[i], i));
        revsp += a[i];
        revsp += val.first;
        hp.insert(val);
      } else
        hp.insert(make_pair(-a[i], i));
    }
  } else if (a[i] < 0) {
    neg.insert(make_pair(a[i], i));
    sumn += a[i];
    if (revn.size() < k) {
      revn.insert(make_pair(a[i], i));
      revsn += a[i];
    } else {
      pair<long long, long long> val = *(revn.rbegin());
      if ((val.first) > a[i]) {
        revn.erase(make_pair(val.first, val.second));
        revn.insert(make_pair(a[i], i));
        revsn += a[i];
        revsn -= val.first;
        hn.insert(val);
      } else
        hn.insert(make_pair(a[i], i));
    }
  }
}
void init() {
  int cnt = 0;
  for (set<pair<long long, long long> >::iterator it = pos.begin();
       it != pos.end(); it++) {
    if (cnt < k) {
      revp.insert(*it);
      revsp -= (*it).first;
    } else
      hp.insert(*it);
    cnt++;
  }
  cnt = 0;
  for (set<pair<long long, long long> >::iterator it = neg.begin();
       it != neg.end(); it++) {
    if (cnt < k) {
      revn.insert(*it);
      revsn += (*it).first;
    } else
      hn.insert(*it);
    cnt++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> len;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> k;
  if (k == 0) {
    long long ans = 0;
    long long fans = 0;
    for (int i = 1; i <= len; i++) {
      ans += a[i];
    }
    for (int i = len + 1; i <= n; i++) {
      fans = max(fans, abs(ans));
      ans += a[i];
      ans -= a[i - len];
    }
    fans = max(fans, ans);
    cout << fans;
    return 0;
  }
  for (int i = 1; i <= len; i++) {
    if (a[i] > 0) {
      pos.insert(make_pair(-a[i], i));
      sump += a[i];
    } else if (a[i] < 0) {
      neg.insert(make_pair(a[i], i));
      sumn += a[i];
    }
  }
  init();
  long long ans = 0;
  for (int j = len + 1; j <= n; j++) {
    ans = max(ans, process());
    int st = j - len;
    erase(st);
    add(j);
  }
  ans = max(ans, process());
  cout << ans;
}
