#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t begin = clock();
  long long n;
  cin >> n;
  vector<long long> cnt(8, 0), final_ans(8, 0);
  for (long long i = 1; i <= n; i++) {
    long long p;
    cin >> p;
    cnt[p]++;
  }
  if (cnt[5] > 0 || cnt[7] > 0 || cnt[3] >= min(cnt[1], cnt[6])) {
    cout << "-1";
    return 0;
  }
  cnt[6] -= cnt[3];
  cnt[1] -= cnt[3];
  final_ans[3] = cnt[3];
  cnt[3] = 0;
  if (cnt[4] <= min(cnt[2], cnt[1])) {
    final_ans[4] = cnt[4];
    cnt[2] -= cnt[4];
    cnt[1] -= cnt[4];
    cnt[4] = 0;
  } else {
    cout << "-1";
    return 0;
  }
  if (cnt[6] <= min(cnt[1], cnt[2])) {
    final_ans[6] = cnt[6];
    cnt[1] -= cnt[6];
    cnt[2] -= cnt[6];
    cnt[6] = 0;
  } else {
    cout << "-1";
    return 0;
  }
  for (long long i = 1; i < 8; i++) {
    if (cnt[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  for (long long i = 1; i < 8; i++) {
    if (i == 3) {
      for (long long j = 0; j < final_ans[i]; j++) cout << "1 3 6\n";
    } else if (i == 4) {
      for (long long j = 0; j < final_ans[i]; j++) cout << "1 2 4\n";
    } else if (i == 6) {
      for (long long j = 0; j < final_ans[i]; j++) cout << "1 2 6\n";
    }
  }
  return 0;
}
