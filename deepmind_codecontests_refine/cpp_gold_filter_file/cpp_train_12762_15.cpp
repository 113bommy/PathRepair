#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x;
  cin >> n;
  long long ara[n + 5], bra[n + 5], cra[n + 5];
  set<long long> s1, s2, s3;
  set<long long>::iterator it;
  map<long long, int> mp1, mp2;
  for (int i = 0; i < n; i++) cin >> ara[i];
  for (int i = 0; i < n; i++) cin >> bra[i];
  for (int i = 0; i < n; i++) cin >> cra[i];
  for (int i = 0; i < n; i++) {
    int a = min(bra[i], cra[i]);
    int b = max(bra[i], cra[i]);
    if (a == 1 && b == 2) {
      s1.insert(ara[i]);
      s2.insert(ara[i]);
      mp1[ara[i]] = 1;
      mp2[ara[i]] = 2;
    } else if (a == 1 && b == 3) {
      s1.insert(ara[i]);
      s3.insert(ara[i]);
      mp1[ara[i]] = 1;
      mp2[ara[i]] = 3;
    } else if (a == 2 && b == 3) {
      s2.insert(ara[i]);
      s3.insert(ara[i]);
      mp1[ara[i]] = 2;
      mp2[ara[i]] = 3;
    } else if (a == 1 && b == 1) {
      s1.insert(ara[i]);
      mp1[ara[i]] = 1;
      mp2[ara[i]] = 1;
    } else if (a == 2 && b == 2) {
      s2.insert(ara[i]);
      mp1[ara[i]] = 2;
      mp2[ara[i]] = 2;
    } else if (a == 3 && b == 3) {
      s3.insert(ara[i]);
      mp1[ara[i]] = 2;
      mp2[ara[i]] = 2;
    }
  }
  cin >> m;
  while (m--) {
    cin >> x;
    if (x == 1) {
      if (s1.empty()) {
        cout << "-1\n";
      } else {
        long long val = *s1.begin();
        int temp = 0;
        if (mp1[val] != x) {
          temp = mp1[val];
        } else if (mp2[val] != x) {
          temp = mp2[val];
        }
        cout << val;
        s1.erase(val);
        if (temp == 2) {
          s2.erase(val);
        } else if (temp == 3) {
          s3.erase(val);
        }
      }
    } else if (x == 2) {
      if (s2.empty()) {
        cout << "-1\n";
      } else {
        long long val = *s2.begin();
        int temp = 0;
        if (mp1[val] != x) {
          temp = mp1[val];
        } else if (mp2[val] != x) {
          temp = mp2[val];
        }
        cout << val;
        s2.erase(val);
        if (temp == 1) {
          s1.erase(val);
        } else if (temp == 3) {
          s3.erase(val);
        }
      }
    } else if (x == 3) {
      if (s3.empty()) {
        cout << "-1\n";
      } else {
        long long val = *s3.begin();
        int temp = 0;
        if (mp1[val] != x) {
          temp = mp1[val];
        } else if (mp2[val] != x) {
          temp = mp2[val];
        }
        cout << val;
        s3.erase(val);
        if (temp == 1) {
          s1.erase(val);
        } else if (temp == 2) {
          s2.erase(val);
        }
      }
    }
    cout << " ";
  }
  return 0;
}
