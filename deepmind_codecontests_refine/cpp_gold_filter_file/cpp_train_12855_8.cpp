#include <bits/stdc++.h>
using namespace std;
int n;
int a[200000];
int ri[200000];
int le[200000];
vector<pair<int, int> > res;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      ri[i] = i;
      continue;
    }
    int j = i + 1;
    while (1) {
      if (a[i] > a[j]) {
        ri[i] = j - 1;
        break;
      }
      if (j == n - 1) {
        ri[i] = j;
        break;
      }
      if (j == ri[j])
        j++;
      else
        j = ri[j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      le[i] = i;
      continue;
    }
    int j = i - 1;
    while (1) {
      if (a[i] > a[j]) {
        le[i] = j + 1;
        break;
      }
      if (j == 0) {
        le[i] = j;
        break;
      }
      if (j == le[j])
        j--;
      else
        j = le[j];
    }
  }
  for (int i = 0; i < n; i++)
    res.push_back(pair<int, int>(a[i], ri[i] - le[i] + 1));
  sort(res.begin(), res.end());
  int k = 0;
  for (int i = res.size() - 1; i >= 0;) {
    if (res[i].second > k) {
      cout << res[i].first << " ";
      k++;
      i++;
    }
    if (k == n) return;
    i--;
  }
}
void gen() {
  freopen("out.txt", "w", stdout);
  srand(time(NULL));
}
int main() {
  solve();
  return 0;
}
