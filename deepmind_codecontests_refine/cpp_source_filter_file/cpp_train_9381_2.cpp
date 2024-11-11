#include <bits/stdc++.h>
using namespace std;
char ss[10];
char s[10000][10];
set<long long> q[10000];
pair<long long, int> fuck[1000000];
int num = 0;
long long fk_hash(char);
int find1(long long);
int find2(long long);
int main() {
  int n, m, qq;
  int x, y;
  long long tmp;
  set<long long>::iterator fk;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", &s[i]);
    m = strlen(s[i]);
    for (int j = 0; j < m; ++j) {
      tmp = 0;
      for (int k = j; k < m; ++k) {
        tmp *= 37;
        tmp += fk_hash(s[i][k]);
        q[i].insert(tmp);
      }
    }
    for (fk = q[i].begin(); fk != q[i].end(); ++fk)
      fuck[num++] = make_pair(*fk, i);
  }
  sort(fuck, fuck + num);
  scanf("%d", &qq);
  for (int i = 0; i < qq; ++i) {
    scanf("%s", ss);
    m = strlen(ss);
    tmp = 0;
    for (int j = 0; j < m; ++j) {
      tmp *= 37;
      tmp += fk_hash(ss[j]);
    }
    y = find2(tmp);
    x = find1(tmp);
    if (x != -1) {
      printf("%d %s\n", y - x + 1, s[fuck[y].second]);
    } else {
      cout << "0 -" << endl;
    }
  }
  return 0;
}
long long fk_hash(char x) {
  if (x >= 'a' && x <= 'z') return x - 'a';
  if (x >= '0' && x <= '9') return x - '0' + 26;
  return 36;
}
int find1(long long x) {
  int l = 0, r = num - 1, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (fuck[mid].first == x) {
      ans = mid;
      r = mid - 1;
    } else if (fuck[mid].first > x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
int find2(long long x) {
  int l = 0, r = num - 1, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (fuck[mid].first == x) {
      ans = mid;
      l = mid + 1;
    } else if (fuck[mid].first > x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
