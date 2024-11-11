#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void eraser(multiset<int> &S, int val) {
  auto it = S.lower_bound(val);
  it++;
  auto it2 = it;
  it--;
  S.erase(it, it2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> P;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    P.push_back(p);
  }
  sort((P).begin(), (P).end());
  multiset<int> vals, gaps, negvals;
  vals.insert(P[0]);
  negvals.insert(-P[0]);
  for (int i = 1; i < n; i++) {
    vals.insert(P[i]);
    negvals.insert(-P[i]);
    gaps.insert(P[i] - P[i - 1]);
  }
  while (1) {
    if (gaps.empty()) {
      cout << 0 << endl;
    } else {
      auto it1 = vals.begin();
      auto it2 = vals.end();
      it2--;
      auto it3 = gaps.end();
      it3--;
      cout << *it2 - *it1 - *it3 << endl;
    }
    if (q == 0) break;
    q--;
    int t, x;
    cin >> t >> x;
    if (t == 0) {
      auto itt1 = vals.upper_bound(x);
      auto itt2 = negvals.upper_bound(-x);
      int relevant_case = -1;
      if (itt1 != vals.end() && itt2 != negvals.end()) relevant_case = 1;
      if (itt1 != vals.end() && itt2 == negvals.end()) relevant_case = 2;
      if (itt1 == vals.end() && itt2 != negvals.end()) relevant_case = 3;
      if (itt1 == vals.end() && itt2 == negvals.end()) relevant_case = 4;
      if (relevant_case == 1) {
        int val1 = *itt1 + *itt2;
        int val2 = *itt1 - x;
        int val3 = x + *itt2;
        gaps.insert(val1);
        eraser(gaps, val2);
        eraser(gaps, val3);
      }
      if (relevant_case == 2) {
        eraser(gaps, *itt1 - x);
      }
      if (relevant_case == 3) {
        eraser(gaps, x + *itt2);
      }
      if (relevant_case == 4) {
      }
      eraser(vals, x);
      eraser(negvals, -x);
    }
    if (t == 1) {
      auto itt1 = vals.upper_bound(x);
      auto itt2 = negvals.upper_bound(-x);
      int relevant_case = -1;
      if (itt1 != vals.end() && itt2 != negvals.end()) relevant_case = 1;
      if (itt1 != vals.end() && itt2 == negvals.end()) relevant_case = 2;
      if (itt1 == vals.end() && itt2 != negvals.end()) relevant_case = 3;
      if (itt1 == vals.end() && itt2 == negvals.end()) relevant_case = 4;
      if (relevant_case == 1) {
        int val1 = *itt1 + *itt2;
        int val2 = *itt1 - x;
        int val3 = x + *itt2;
        eraser(gaps, val1);
        gaps.insert(val2);
        gaps.insert(val3);
      }
      if (relevant_case == 2) {
        gaps.insert(*itt1 - x);
      }
      if (relevant_case == 3) {
        gaps.insert(x + *itt2);
      }
      if (relevant_case == 4) {
      }
      vals.insert(x);
      negvals.insert(-x);
    }
  }
}
