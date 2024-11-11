#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
const int NMax = 1e2 + 5;
const ll inf_ll = 1e18 + 5;
const int inf_int = 1e9 + 5;
const int mod = 100003;
using zint = int;
int N, M, sum;
int col[NMax], need[NMax];
bool canUse(int len) {
  vector<int> curr(M + 1, 0);
  for (int i = 1; i <= len; ++i) {
    ++curr[col[i]];
  }
  int nrMatch = 0;
  for (int j = 1; j <= M; ++j) {
    if (curr[j] >= need[j]) {
      ++nrMatch;
    }
  }
  if (nrMatch == M) {
    return true;
  }
  for (int i = len + 1; i <= N; ++i) {
    --curr[col[i - len]];
    if (curr[col[i - len]] == need[col[i - len]] - 1) {
      --nrMatch;
    }
    ++curr[col[i]];
    if (curr[col[i]] == need[col[i]]) {
      ++nrMatch;
    }
    if (nrMatch == M) {
      return true;
    }
  }
  return false;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> col[i];
  }
  for (int i = 1; i <= M; ++i) {
    cin >> need[i];
    sum += need[i];
  }
  if (canUse(sum)) {
    cout << 0;
    return 0;
  }
  int pw = 1, len = sum;
  for (; pw <= N; pw <<= 1)
    ;
  pw >>= 1;
  while (pw) {
    if (len + pw <= N && !canUse(len + pw)) {
      len += pw;
    }
    pw >>= 1;
  }
  cout << (canUse(len + 1) ? len + 1 - sum : -1) << '\n';
  return 0;
}
