#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int p[n];
    int oc = 0;
    int ec = 0;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      oc += p[i] % 2;
      if (p[i] != 0 && p[i] % 2 == 0) ec++;
    }
    if (n == 1) {
      cout << "0";
      break;
    } else if (oc == 0 && ec == 0) {
      cout << "1";
      break;
    }
    vector<int> oo;
    vector<int> ee;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (p[i] != 0 && p[i + 1] != 0 && p[i] % 2 != p[i + 1] % 2) ans++;
    }
    int c1[2];
    int ctre = 0;
    int c2[2];
    int ctro = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0 && p[i] == 0) {
        int j = i;
        while (j < n && p[j] == 0) j++;
        if (p[j] % 2 == 0)
          c1[ctre++] = j;
        else
          c2[ctro++] = j;
        i = j - 1;
      } else if (p[i] == 0) {
        int j = i;
        while (j < n && p[j] == 0) j++;
        if (j == n) {
          if (p[i - 1] % 2 == 0)
            c1[ctre++] = j;
          else
            c2[ctro++] = j;
        } else if (j < n && p[i - 1] % 2 != p[j] % 2) {
          ans++;
        } else {
          if (p[i - 1] % 2 == 0)
            ee.push_back(j - i);
          else
            oo.push_back(j - i);
        }
        i = j - 1;
      }
    }
    sort(oo.begin(), oo.end());
    sort(c1, c1 + ctre);
    sort(ee.begin(), ee.end());
    sort(c2, c2 + ctro);
    oc = n / 2 + n % 2 - oc;
    ec = n / 2 - ec;
    for (int i = 0; i < oo.size(); i++) {
      if (oo[i] > oc) {
        ans += (oo.size() - i) * 2;
        break;
      }
      oc -= oo[i];
    }
    for (int j = 0; j < ctro; j++) {
      if (c2[j] <= oc)
        oc -= c2[j];
      else
        ans++;
    }
    for (int i = 0; i < ee.size(); i++) {
      if (ee[i] > ec) {
        ans += (ee.size() - i) * 2;
        break;
      }
      ec -= ee[i];
    }
    for (int j = 0; j < ctre; j++) {
      if (c1[j] <= ec)
        ec -= c1[j];
      else
        ans++;
    }
    cout << ans << "\n";
  }
}
