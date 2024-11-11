#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > arr[4];
set<pair<int, int> > s1, s2;
int sumK;
int getT(int m) {
  while (!s1.empty() and !s2.empty() and *(--s1.end()) > *(s2.begin())) {
    auto a = *(--s1.end());
    auto b = *(s2.begin());
    s2.erase(s2.begin());
    s1.erase(--s1.end());
    sumK -= a.first;
    sumK += b.first;
    s1.insert(b);
    s2.insert(a);
  }
  while (s1.size() < m and !s2.empty()) {
    sumK += (*s2.begin()).first;
    s1.insert(*s2.begin());
    s2.erase(s2.begin());
  }
  return sumK;
}
void apply1(int &i, int &curr) {
  s2.insert(arr[1][i]);
  s2.insert(arr[2][i]);
  curr -= arr[1][i].first + arr[2][i].first;
  i--;
}
void apply2(int &j, int &curr) {
  curr += arr[3][j].first;
  auto it = s2.find(arr[3][j]);
  auto it2 = s1.find(arr[3][j]);
  if (it != s2.end()) {
    s2.erase(it);
  } else {
    s1.erase(it2);
    sumK -= arr[3][j].first;
  }
  j++;
}
void prepare(int n1, int n2, int m1) {
  int i;
  for (i = n1; i < n2; ++i) {
    s2.insert(arr[3][i]);
  }
  for (i = 0; i < arr[0].size(); ++i) {
    s2.insert(arr[0][i]);
  }
  for (i = m1; i < arr[1].size(); ++i) {
    s2.insert(arr[1][i]);
  }
  for (i = m1; i < arr[2].size(); ++i) {
    s2.insert(arr[2][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, a, b, c, i, j, mask, ans, m1, m, curr;
  cin >> n >> m >> k;
  for (i = 0; i < n; ++i) {
    cin >> a >> b >> c;
    mask = c;
    mask += 2 * b;
    arr[mask].emplace_back(a, i + 1);
  }
  for (i = 1; i <= 3; ++i) {
    sort(arr[i].begin(), arr[i].end());
  }
  m1 = min(arr[1].size(), arr[2].size());
  n = arr[3].size();
  prepare(0, n, m1);
  curr = 0;
  for (i = 0; i < m1; ++i) {
    curr += arr[1][i].first + arr[2][i].first;
  }
  i = m1 - 1;
  while (i >= 0 and i + 1 > k) {
    apply1(i, curr);
  }
  j = 0;
  while (j < n and j + i + 1 < k) {
    apply2(j, curr);
  }
  a = b = -1000000000;
  c = 2 * 1000000000;
  if (i + 1 + j == k) {
    while (i >= 0 and j < n and k + i + 1 > m) {
      apply1(i, curr);
      apply2(j, curr);
    }
    if (k + i + 1 <= m) {
      ans = curr + getT(m - k - i - 1);
      if (c > ans) {
        a = i;
        b = j;
        c = ans;
      }
      while (i >= 0 and j < n) {
        apply1(i, curr);
        apply2(j, curr);
        ans = curr + getT(m - k - i - 1);
        if (c > ans) {
          a = i;
          b = j;
          c = ans;
        }
      }
    }
  }
  if (a != -1000000000) {
    cout << c << "\n";
    for (i = 0; i <= a; ++i) {
      cout << arr[1][i].second << " " << arr[2][i].second << " ";
    }
    for (i = 0; i < b; ++i) {
      cout << arr[3][i].second << " ";
    }
    s2.clear();
    prepare(b, n, a + 1);
    for (i = 0; i < m - k - a - 1; ++i) {
      auto z = *s2.begin();
      s2.erase(s2.begin());
      cout << z.second << " ";
    }
  } else {
    cout << "-1";
  }
  return 0;
}
