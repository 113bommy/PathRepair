#include <bits/stdc++.h>
using namespace std;
int N;
long long A[200005], B[200005], DP[200005];
vector<pair<long long, long long> > lines;
void add(pair<long long, long long> x) {
  if (lines.size() < 2)
    lines.push_back(x);
  else {
    while (lines.size() >= 2) {
      pair<long long, long long> old1 = lines[lines.size() - 2];
      pair<long long, long long> old2 = lines[lines.size() - 1];
      long double sold = (long double)(x.second - old2.second) /
                         (long double)(old2.first - x.first);
      long double snew = (long double)(x.second - old1.second) /
                         (long double)(old1.first - x.first);
      if (snew >= sold) {
        lines.pop_back();
      } else {
        break;
      }
    }
    lines.push_back(x);
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  DP[0] = 0LL;
  add({B[0], 0LL});
  for (int i = 1; i < N; i++) {
    int l = 0, r = lines.size() - 1, mid;
    for (int z = 0; z < 60; z++) {
      mid = (l + r) / 2;
      if (lines[mid].first * A[i] + lines[mid].second <
          lines[mid + 1].first * A[i] + lines[mid + 1].second) {
        r = mid;
      } else {
        l = mid;
      }
    }
    DP[i] = 1LL * lines[r].first * A[i] + lines[r].second;
    add({B[i], DP[i]});
  }
  cout << DP[N - 1] << "\n";
  return 0;
}
