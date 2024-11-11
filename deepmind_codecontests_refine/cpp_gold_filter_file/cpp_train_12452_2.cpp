#include <bits/stdc++.h>
using namespace std;
bool Can(const vector<int>& P, const vector<int>& S, int T) {
  int s_pos = 0;
  for (int p : P) {
    if (s_pos == S.size()) {
      break;
    }
    int avaliable = T;
    if (p < S[s_pos]) {
      int dist = S[s_pos] - p;
      avaliable -= dist;
      if (avaliable < 0) {
        continue;
      }
      ++s_pos;
      while (s_pos < S.size()) {
        int dist = S[s_pos] - S[s_pos - 1];
        avaliable -= dist;
        if (avaliable < 0) {
          break;
        }
        ++s_pos;
      }
      continue;
    }
    int dist = p - S[s_pos];
    if (dist > avaliable) {
      return false;
    }
    int lo = s_pos, hi = S.size();
    while (lo < hi) {
      int med = (lo + hi) / 2;
      int dist1 = p - S[s_pos] + S[med] - S[s_pos];
      int dist2 = abs(S[med] - p) + S[med] - S[s_pos];
      if (min(dist1, dist2) <= avaliable) {
        lo = med + 1;
      } else {
        hi = med;
      }
    }
    s_pos = lo;
  }
  return s_pos == S.size();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  string F;
  cin >> F;
  vector<int> P, S;
  for (int i = 0; i < N; ++i) {
    switch (F[i]) {
      case '*':
        S.push_back(i);
        break;
      case 'P':
        P.push_back(i);
        break;
      default:
        break;
    }
  }
  int lo = 0, hi = 2 * N;
  while (lo < hi) {
    int med = (lo + hi) / 2;
    if (Can(P, S, med)) {
      hi = med;
    } else {
      lo = med + 1;
    }
  }
  cout << lo << '\n';
  return 0;
}
