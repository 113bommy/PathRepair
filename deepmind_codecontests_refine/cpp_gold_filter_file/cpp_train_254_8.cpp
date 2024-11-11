#include <bits/stdc++.h>
using namespace std;
const int MX = (1 << 20);
int to_number(string str) {
  int ret = 0, st = 0;
  if (str[0] == '-') st = 1;
  for (int j = st; j < str.length(); j++) ret *= 10, ret += str[j] - '0';
  if (st) ret *= -1;
  return ret;
}
int n, arr[MX], K, q = 0, pref = 0;
string tt;
bool is[MX];
void process(int st, vector<pair<int, int> > v) {
  int sz = (n - st) / K;
  if (v.empty()) {
    int V = -1 * sz / 2;
    for (int j = st; j <= n; j += K) arr[j] = V++;
    return;
  }
  int dif = (v[0].first - st) / K;
  int V = min(v[0].second - 1, dif / 2);
  for (int j = v[0].first - K; j > 0; j -= K) {
    arr[j] = V--, is[j] = 0;
  }
  int omar = v.size(), med, D;
  for (int j = 1; j < omar; j++) {
    dif = (v[j].first - v[j - 1].first) / K;
    if (dif - 1 > abs(v[j].second - v[j - 1].second)) {
      puts("Incorrect sequence");
      exit(0);
    }
    if (dif == 1) continue;
    med = v[j - 1].first + (dif / 2 + dif % 2) * K;
    arr[med] = 0;
    for (int i = med + K; i < v[j].first; i += K) arr[i] = arr[i - K] + 1;
    for (int i = med - K; i > v[j - 1].first; i -= K) arr[i] = arr[i + K] - 1;
    D = min(0, arr[v[j].first] - arr[v[j].first - K] - 1);
    if (!D) D = max(D, arr[v[j - 1].first] - arr[v[j - 1].first + K] + 1);
    for (int i = v[j - 1].first + K; i < v[j].first; i += K) arr[i] += D;
  }
  dif = (n - v[omar - 1].first) / K;
  V = max(v[omar - 1].second + 1, -1 * dif / 2);
  for (int j = v[omar - 1].first + K; j <= n; j += K) arr[j] = V++, is[j] = 0;
}
int main() {
  cin >> n >> K;
  for (int j = 1; j <= n; j++) {
    cin >> tt;
    if (tt == "?")
      is[j] = 1, q++;
    else
      arr[j] = to_number(tt);
  }
  for (int j = K + 1; j <= n; j++) {
    if (is[j] || is[j - K]) continue;
    if (arr[j] <= arr[j - K]) {
      puts("Incorrect sequence");
      return 0;
    }
  }
  for (int j = 1; j <= K; j++) {
    vector<pair<int, int> > v;
    int ss = 1;
    for (int i = j; i <= n; i += K) {
      if (!is[i]) {
        v.push_back(make_pair(i, arr[i]));
      }
    }
    process(j, v);
  }
  for (int j = K + 1; j <= n; j++) {
    if (is[j] && is[j - K]) continue;
    if (arr[j] <= arr[j - K]) {
      puts("Incorrect sequence");
      return 0;
    }
  }
  for (int j = 1; j <= n; j++) cout << arr[j] << ' ';
}
