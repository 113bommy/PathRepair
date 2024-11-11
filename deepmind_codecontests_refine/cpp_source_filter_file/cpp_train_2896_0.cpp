#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<long long> B;
  for (int i = 0; i < N - 1; i++) {
    long long tmp = 0;
    for (int j = i; j < N; j++) {
      tmp += A.at(j);
      B.push_back(tmp);
    }
  }
  long long ans = 0;
  for (int i = 0; i < 40; i++) {
    vector<long long> cands;
    for (long long v : B) {
      bitset<40> s(v);
      if (s.test(39 - i)) cands.push_back(v);
    }
    if (cands.size() >= K) {
      ans += (1 << (39 - i));
      B.swap(cands);
    }
  }
  cout << ans << endl;
}
