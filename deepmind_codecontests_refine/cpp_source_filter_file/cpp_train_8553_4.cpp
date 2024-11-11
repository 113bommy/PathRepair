#include <bits/stdc++.h>
using namespace std;
struct fenvick {
  vector<bool> got;
  vector<long long> fen;
  fenvick() {}
  fenvick(int n) {
    fen.resize(n);
    got.resize(n);
  }
  void upd(int pos) {
    if (got[pos] == true) {
      return;
    }
    got[pos] = true;
    while (pos < fen.size()) {
      fen[pos]++;
      pos |= (pos + 1);
    }
  }
  long long getPref(int pos) {
    if (pos < 0) {
      return 0;
    }
    long long res = 0;
    while (pos >= 0) {
      res += fen[pos];
      pos &= (pos + 1);
      pos--;
    }
    return res;
  }
  long long getSum(int l, int r) { return getPref(r) - getPref(l - 1); }
};
bool comp(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second > b.second;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, cur = 0, ans = 0;
  cin >> n;
  vector<pair<long long, long long>> arr(n);
  vector<bool> used;
  map<long long, int> cnt, indX;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    cnt[arr[i].first]++;
  }
  sort(arr.begin(), arr.end(), comp);
  used.resize(cnt.size());
  for (auto to : cnt) {
    indX[to.first] = cur;
    cur++;
  }
  fenvick sosi(cnt.size());
  for (int i = 0; i < n; i++) {
    int pos = indX[arr[i].first];
    int tmpI = i;
    while (tmpI < n) {
      if (used[tmpI]) {
        break;
      }
      if (arr[tmpI].second == arr[i].second) {
        used[tmpI] = true;
        sosi.upd(indX[arr[tmpI].first]);
        tmpI++;
      } else {
        break;
      }
    }
    long long l0 = 0, r0 = cnt.size() - 1;
    if (i > 0) {
      if (arr[i - 1].second == arr[i].second) {
        l0 = indX[arr[i - 1].first] + 1;
      }
    }
    ans += sosi.getSum(l0, pos) * sosi.getSum(pos, r0);
  }
  cout << ans << '\n';
  return 0;
}
