#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXA = 1 << 20;
int n, m, k, niz[MAXN], pref[MAXN], currentL, currentR;
long long ans = 0, cnt[MAXA];
const int BLOCK = 317;
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  if (a.first / BLOCK == b.first / BLOCK)
    return a.second.first < b.second.first;
  return a.first < b.first;
}
pair<int, pair<int, int> > queries[MAXN];
int ispis[MAXN];
void add(int position) {
  ans += cnt[pref[position] ^ k];
  cnt[pref[position]]++;
}
void remove(int position) {
  cnt[pref[position]]--;
  ans -= cnt[pref[position] ^ k];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> niz[i];
    pref[i] = pref[i - 1] ^ niz[i];
  }
  currentL = 1, currentR = 1;
  add(0);
  add(1);
  for (int i = 0; i < m; i++) {
    cin >> queries[i].first >> queries[i].second.first;
    queries[i].second.second = i;
  }
  sort(queries, queries + m, cmp);
  for (int i = 0; i < m; i++) {
    int l = queries[i].first, r = queries[i].second.first;
    while (currentL < l) {
      remove(currentL - 1);
      currentL++;
    }
    while (currentL > l) {
      currentL--;
      add(currentL - 1);
    }
    while (currentR < r) {
      currentR++;
      add(currentR);
    }
    while (currentR > r) {
      remove(currentR);
      currentR--;
    }
    ispis[queries[i].second.second] = ans;
  }
  for (int i = 0; i < m; i++) cout << ispis[i] << endl;
  return 0;
}
