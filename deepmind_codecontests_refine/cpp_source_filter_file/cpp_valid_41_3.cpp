#include <bits/stdc++.h>
using namespace std;
long long SET(long long n, long long pos) { return n = n | (1 << pos); }
long long RESET(long long n, long long pos) { return n = n & ~(1 << pos); }
bool CHECK(long long n, long long pos) { return (bool)(n & (1 << pos)); }
vector<long long> v;
long long x, y, z, a, b, c, sum, ans, total, t, cnt, n, m, k, p, q, r, l, wrow,
    col, kase;
string s1, s2;
map<long long, long long> mp;
set<long long> s;
map<long long, long long>::iterator itr1, ptr1;
set<long long>::iterator itr, ptr;
long long arr[6][3000009];
void abc() {
  for (long long i = 0; i < s1.size(); i++) {
    if (i % 3 == 0) {
      if (s1[i] != 'a') arr[0][i] = 1;
      if (i != 0) arr[0][i] += arr[0][i - 1];
    } else if (i % 3 == 1) {
      if (s1[i] != 'b') arr[0][i] = 1;
      if (i != 0) arr[0][i] += arr[0][i - 1];
    } else {
      if (s1[i] != 'c') arr[0][i] = 1;
      if (i != 0) arr[0][i] += arr[0][i - 1];
    }
  }
}
void acb() {
  for (long long i = 0; i < s1.size(); i++) {
    if (i % 3 == 0) {
      if (s1[i] != 'a') arr[1][i] = 1;
      if (i != 0) arr[1][i] += arr[1][i - 1];
    } else if (i % 3 == 1) {
      if (s1[i] != 'c') arr[1][i] = 1;
      if (i != 0) arr[1][i] += arr[1][i - 1];
    } else {
      if (s1[i] != 'b') arr[1][i] = 1;
      if (i != 0) arr[1][i] += arr[1][i - 1];
    }
  }
}
void bca() {
  for (long long i = 0; i < s1.size(); i++) {
    if (i % 3 == 0) {
      if (s1[i] != 'b') arr[2][i] = 1;
      if (i != 0) arr[2][i] += arr[2][i - 1];
    } else if (i % 3 == 1) {
      if (s1[i] != 'c') arr[2][i] = 1;
      if (i != 0) arr[2][i] += arr[2][i - 1];
    } else {
      if (s1[i] != 'a') arr[2][i] = 1;
      if (i != 0) arr[2][i] += arr[2][i - 1];
    }
  }
}
void bac() {
  for (long long i = 0; i < s1.size(); i++) {
    if (i % 3 == 0) {
      if (s1[i] != 'b') arr[3][i] = 1;
      if (i != 0) arr[3][i] += arr[3][i - 1];
    } else if (i % 3 == 1) {
      if (s1[i] != 'a') arr[3][i] = 1;
      if (i != 0) arr[3][i] += arr[3][i - 1];
    } else {
      if (s1[i] != 'c') arr[3][i] = 1;
      if (i != 0) arr[3][i] += arr[3][i - 1];
    }
  }
}
void cba() {
  for (long long i = 0; i < s1.size(); i++) {
    if (i % 3 == 0) {
      if (s1[i] != 'c') arr[4][i] = 1;
      if (i != 0) arr[4][i] += arr[4][i - 1];
    } else if (i % 3 == 1) {
      if (s1[i] != 'b') arr[4][i] = 1;
      if (i != 0) arr[4][i] += arr[4][i - 1];
    } else {
      if (s1[i] != 'a') arr[4][i] = 1;
      if (i != 0) arr[4][i] += arr[4][i - 1];
    }
  }
}
void cab() {
  for (long long i = 0; i < s1.size(); i++) {
    if (i % 3 == 0) {
      if (s1[i] != 'c') arr[5][i] = 1;
      if (i != 0) arr[5][i] += arr[5][i - 1];
    } else if (i % 3 == 1) {
      if (s1[i] != 'a') arr[5][i] = 1;
      if (i != 0) arr[5][i] += arr[5][i - 1];
    } else {
      if (s1[i] != 'b') arr[5][i] = 1;
      if (i != 0) arr[5][i] += arr[5][i - 1];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  cin >> s1;
  abc();
  bac();
  acb();
  bca();
  cab();
  cba();
  while (m--) {
    cin >> x >> y;
    ans = INT_MAX;
    x--;
    y--;
    for (long long i = 0; i < 6; i++) {
      if (i != 0)
        ans = min(ans, arr[i][y] - arr[i][x - 1]);
      else
        ans = min(ans, arr[i][y]);
    }
    cout << ans << "\n";
  }
  return 0;
}
