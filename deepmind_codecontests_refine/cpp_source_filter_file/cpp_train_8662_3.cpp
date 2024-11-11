#include <bits/stdc++.h>
using namespace std;
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    cin >> a[i];
  if (n == 1) {
    cout << "0";
    return 0;
  }
  vector<long long> o1, o2, e1, e2;
  long long ans = 0;
  vector<long long> vis(n + 1, 1);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    vis[a[i]] = 0;
  }
  long long cnto = 0, cnte = 0;
  for (__typeof(n + 1) i = (1) - ((1) > (n + 1));
       i != (n + 1) - ((1) > (n + 1)); i += 1 - 2 * ((1) > (n + 1))) {
    if (vis[i] == 1) {
      if (i % 2)
        cnto++;
      else
        cnte++;
    }
  }
  long long cnt = 0, k = -1;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (a[i] == 0)
      cnt++;
    else {
      if (cnt > 0) {
        if (k == -1) {
          if (a[i] % 2)
            o2.push_back(cnt);
          else
            e2.push_back(cnt);
        } else if (k == 0) {
          if (a[i] % 2)
            ans++;
          else
            e1.push_back(cnt);
        } else if (k == 1) {
          if (a[i] % 2) {
            o1.push_back(cnt);
          } else
            ans++;
        }
      } else if (k == 1 && (a[i] % 2 == 0))
        ans++;
      else if (k == 0 && a[i] % 2)
        ans++;
      cnt = 0;
      if (a[i] % 2)
        k = 1;
      else
        k = 0;
    }
  }
  if (cnt > 0) {
    if (k == (-1)) {
      if (a[n - 1] % 2)
        o2.push_back(cnt);
      else
        e2.push_back(cnt);
    } else if (k == 0) {
      e2.push_back(cnt);
    } else if (k == 1) {
      o2.push_back(cnt);
    }
  }
  sort((o1).begin(), (o1).end());
  sort((o2).begin(), (o2).end());
  sort((e1).begin(), (e1).end());
  sort((e2).begin(), (e2).end());
  long long i = 0, j = 0;
  while (1 && (j < (long long)o2.size() && i < (long long)o1.size())) {
    if (cnto < o1[i]) {
      if (cnto > o2[j]) {
        cnto -= o2[j];
        j++;
      } else
        break;
    } else if (cnto < o2[j]) {
      if (cnto > o1[i]) {
        cnto -= o1[i];
        i++;
      }
    } else if (j < ((long long)o2.size() - 1)) {
      if (o1[i] >= (o2[j] + o2[j + 1])) {
        cnto -= (o2[j] + o2[j + 1]);
        j++;
        j++;
      } else {
        cnto -= o1[i];
        i++;
      }
    } else {
      cnto -= o1[i];
      i++;
    }
  }
  for (long long l = i; l < (long long)o1.size(); l++) {
    if (cnto >= o1[l])
      cnto -= o1[l];
    else
      ans += 2;
  }
  for (long long l = j; l < (long long)o2.size(); l++) {
    if (cnto >= o2[l]) {
      cnto -= o2[l];
    } else
      ans += 1;
  }
  i = 0, j = 0;
  while (1 && (j < (long long)e2.size() && i < (long long)e1.size())) {
    if (cnto < e1[i]) {
      if (cnte > e2[j]) {
        cnte -= e2[j];
        j++;
      } else
        break;
    } else if (cnte < e2[j]) {
      if (cnte > e1[i]) {
        cnte -= e1[i];
        i++;
      }
    } else if (j < ((long long)e2.size() - 1)) {
      if (e1[i] >= (e2[j] + e2[j + 1])) {
        cnte -= (e2[j] + e2[j + 1]);
        j++;
        j++;
      } else {
        cnte -= e1[i];
        i++;
      }
    } else {
      cnte -= e1[i];
      i++;
    }
  }
  for (long long l = i; l < (long long)e1.size(); l++) {
    if (cnte >= e1[l])
      cnte -= e1[l];
    else
      ans += 2;
  }
  for (long long l = j; l < (long long)e2.size(); l++) {
    if (cnte >= e2[l])
      cnte -= e2[l];
    else
      ans += 1;
  }
  cout << ans << '\n';
}
