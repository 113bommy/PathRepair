#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m, kb;
int a[100009], szs[350], mas[350][3 * 300], cnt[350][100009];
int del(int block, int pos) {
  int val = mas[block][pos];
  cnt[block][val]--;
  for (int i = pos + 1; i <= szs[block]; i++) mas[block][i - 1] = mas[block][i];
  szs[block]--;
  return val;
}
void add(int block, int pos, int val) {
  szs[block]++;
  for (int i = szs[block]; i > pos; i--) mas[block][i] = mas[block][i - 1];
  mas[block][pos] = val;
  cnt[block][val]++;
}
pair<int, int> getnum(int num) {
  int sum = 0, s1 = num, s2 = 0;
  for (int i = 1; i <= kb; i++) {
    if (sum + szs[i] < num)
      sum += szs[i];
    else {
      return {num - sum, i};
    }
  }
  if (s2 == 0) s2 = kb;
  return {s1, s2};
}
int query(int l, int r, int val) {
  int k1 = l, k2 = r, b1, b2, sum = 0, res = 0;
  pair<int, int> s = getnum(l);
  b1 = s.second;
  k1 = s.first;
  s = getnum(r);
  b2 = s.second;
  k2 = s.first;
  for (int i = k1; i <= (b1 == b2 ? k2 : szs[b1]); i++)
    if (mas[b1][i] == val) res++;
  if (b1 != b2)
    for (int i = 1; i <= k2; i++)
      if (mas[b2][i] == val) res++;
  for (int i = b1 + 1; i <= b2 - 1; i++) res += cnt[i][val];
  return res;
}
int lastans = 0;
void form() {
  for (int i = 1; i <= n; i++) {
    mas[i / 300 + 1][++szs[i / 300 + 1]] = a[i];
    cnt[i / 300 + 1][a[i]]++;
    kb = max(kb, i / 300 + 1);
  }
}
void ins() {
  int sz = 0;
  for (int i = 1; i <= kb; i++) {
    for (int j = 1; j <= szs[i]; j++) {
      a[++sz] = mas[i][j];
      cnt[i][mas[i][j]]--;
    }
    szs[i] = 0;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  form();
  cin >> m;
  for (i = 1; i <= m; i++) {
    if (i % 300 == 0) {
      ins();
      form();
    }
    int p;
    cin >> p >> k >> l;
    k = ((k + lastans - 1) % n) + 1;
    l = ((l + lastans - 1) % n) + 1;
    if (k > l) swap(k, l);
    if (p == 1) {
      pair<int, int> s = getnum(k);
      int b1 = s.second, k1 = s.first;
      s = getnum(l);
      int b2 = s.second, k2 = s.first;
      add(b1, k1, del(b2, k2));
    } else {
      int t;
      cin >> t;
      t = ((t + lastans - 1) % n) + 1;
      lastans = query(k, l, t);
      cout << lastans << endl;
    }
  }
  exit(0);
}
