#include <bits/stdc++.h>
using namespace std;
struct elements {
  long long cnt;
  char c;
};
const int MAXN = 2 * 1e5 + 5;
elements s[MAXN], t[MAXN];
int lps[MAXN], kmp[MAXN], tsize, ssize;
void get_input();
void check();
void make_lps(), find_lps(int);
void make_kmp(), find_kmp(int);
int num(string);
bool one_character();
int main() {
  get_input();
  if (one_character()) {
    return 0;
  }
  make_lps();
  make_kmp();
}
void find_kmp(int i) {
  if (i <= 1) {
    kmp[i] = i - 1;
    return;
  }
  int j = kmp[i - 1];
  kmp[i] = -1;
  while (kmp[i] == -1) {
    if (j == -1) {
      kmp[i] = 0;
      return;
    }
    if (s[i - 2].c == t[j].c && s[i - 2].cnt >= t[j].cnt) {
      if ((j == 1 || j == 0) || s[i - 3].cnt == t[j - 1].cnt) {
        kmp[i] = j + 1;
        return;
      }
    }
    j = lps[j];
  }
}
void make_kmp() {
  long long res = 0;
  for (int i = 0; i <= ssize + 1; i++) {
    find_kmp(i);
    if (kmp[i] == tsize) res++;
  }
  cout << res << endl;
}
bool one_character() {
  if (tsize > 1) {
    return false;
  }
  long long res = 0;
  char c = t[0].c;
  int cnt = t[0].cnt;
  for (int i = 0; i < ssize; i++)
    if (s[i].c == c) res += max(s[i].cnt - cnt + 1, 1ll * 0);
  cout << res << endl;
  return true;
}
void find_lps(int i) {
  if (i <= 1) {
    lps[i] = i - 1;
    return;
  }
  int j = lps[i - 1];
  lps[i] = -1;
  while (lps[i] == -1) {
    if (j == -1) {
      lps[i] = 0;
      return;
    }
    if (t[i - 1].c == t[j].c && t[i - 1].cnt >= t[j].cnt) {
      if (j == 0 || t[i - 2].cnt == t[j - 1].cnt) {
        lps[i] = j + 1;
        return;
      }
    }
    j = lps[j];
  }
}
void make_lps() {
  for (int i = 0; i <= tsize; i++) find_lps(i);
}
void check() {
  for (int i = 0; i < ssize; i++) {
    cout << s[i].cnt << ' ' << s[i].c << endl;
  }
}
int num(string a) {
  int res = 0;
  for (int i = 0; i < a.size() - 2; i++) {
    int t = a[i] - '0';
    res = res * 10 + t;
  }
  return res;
}
void get_input() {
  int n, m;
  cin >> n >> m;
  ssize = 0;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    int size = a.size();
    if (ssize > 0 && a[size - 1] == s[ssize - 1].c)
      s[ssize - 1].cnt += num(a);
    else {
      s[ssize].cnt = num(a);
      s[ssize].c = a[size - 1];
      ssize++;
    }
  }
  tsize = 0;
  for (int i = 0; i < m; i++) {
    string a;
    cin >> a;
    int size = a.size();
    if (tsize > 0 && a[size - 1] == t[tsize - 1].c)
      t[tsize - 1].cnt += num(a);
    else {
      t[tsize].cnt = num(a);
      t[tsize].c = a[size - 1];
      tsize++;
    }
  }
}
