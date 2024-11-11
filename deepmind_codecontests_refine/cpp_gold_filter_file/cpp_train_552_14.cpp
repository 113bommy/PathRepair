#include <bits/stdc++.h>
using namespace std;
struct hasil {
  long long score;
  long long penalty;
  hasil(long long b, long long c) {
    this->score = b;
    this->penalty = c;
  }
  bool operator<(const hasil& banding) const {
    if (score == banding.score) {
      return (penalty < banding.penalty);
    }
    return (score > banding.score);
  }
};
int main() {
  long long n, k;
  cin >> n >> k;
  map<hasil, long long> m;
  vector<hasil> v;
  for (int i = 0; i < n; i++) {
    long long s, p;
    cin >> s >> p;
    v.push_back(hasil(s, p));
    m[hasil(s, p)]++;
  }
  sort(v.begin(), v.end());
  cout << m[v[k - 1]] << "\n";
}
