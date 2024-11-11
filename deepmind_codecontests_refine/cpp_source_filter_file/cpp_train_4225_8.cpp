#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 200100;
int a[maxn];
map<int, int> st;
int sum = 0;
int x1 = 0, x2 = 0;
map<int, int> has1, has2;
vector<int> av;
int ans[maxn];
int kol = 0;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (st[a[i]]) av.push_back(i);
    st[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    int num = st[a[i]];
    if (num > 1) {
      sum += (num - 1);
    }
    st[a[i]] = 1;
    if (a[i] % 2 && !has2[a[i]]) {
      x2++;
      has2[a[i]] = i;
    } else if (a[i] % 2 == 0 && !has1[a[i]]) {
      x1++;
      has1[a[i]] = i;
    }
  }
  int curc = 2;
  int curn = 1;
  while (1) {
    if (x1 == x2 && x1 == n / 2) break;
    bool ff = 0;
    if (x1 == x2) {
      ff = 1;
    }
    while (x1 < x2 || ff) {
      if (ff) ff = 0;
      if (sum) {
        sum--;
        kol++;
        if (curc > m) {
          cout << -1 << endl;
          return 0;
        }
        while (has1[curc]) {
          curc += 2;
          if (curc > m) {
            cout << -1 << endl;
            return 0;
          }
        }
        x1++;
        has1[curc] = av[av.size() - 1];
        av.pop_back();
      } else {
        kol++;
        x2--;
        map<int, int>::iterator it = has2.begin();
        if (curc > m) {
          cout << -1 << endl;
          return 0;
        }
        while (has1[curc]) {
          curc += 2;
          if (curc > m) {
            cout << -1 << endl;
            return 0;
          }
        }
        x1++;
        has1[curc] = it->second;
        has2.erase(it);
      }
    }
    while (x2 < x1) {
      if (sum) {
        kol++;
        sum--;
        if (curn > m) {
          cout << -1 << endl;
          return 0;
        }
        while (has1[curn]) {
          curn += 2;
          if (curn > m) {
            cout << -1 << endl;
            return 0;
          }
        }
        x2++;
        has1[curn] = av[av.size() - 1];
        av.pop_back();
      } else {
        kol++;
        x1--;
        map<int, int>::iterator it = has1.begin();
        if (curn > m) {
          cout << -1 << endl;
          return 0;
        }
        while (has2[curn]) {
          curn += 2;
          if (curn > m) {
            cout << -1 << endl;
            return 0;
          }
        }
        x2++;
        has2[curn] = it->second;
        has1.erase(it);
      }
    }
  }
  for (map<int, int>::iterator it = has1.begin(); it != has1.end(); it++) {
    ans[it->second] = it->first;
  }
  for (map<int, int>::iterator it = has2.begin(); it != has2.end(); it++) {
    ans[it->second] = it->first;
  }
  cout << kol << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
