#include <bits/stdc++.h>
using namespace std;
struct Course {
  int s, e, id, c;
  Course(int _s, int _e, int _id, int _c) : s(_s), e(_e), id(_id), c(_c) {}
};
class Solution {
 public:
  vector<int> schedule(vector<Course>& C) {
    sort(begin(C), end(C), [](Course a, Course b) {
      return (a.s < b.s) || (a.s == b.s && a.e < b.e);
    });
    int cnt = 0, n = C.size();
    for (int i = 0, j = 1; j < n; ++j) {
      if (C[j].s < C[i].e) {
        if (j + 1 < n && C[j + 1].s < min(C[i].e, C[j].e)) return {};
        ++C[i].c, ++C[j].c, ++cnt;
        if (C[j].e >= C[i].e) ++i;
      } else
        ++i;
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (C[i].c == cnt) res.push_back(C[i].id);
    }
    if (!res.empty()) sort(begin(res), end(res));
    return res;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solution s;
  int n, L, R;
  while (cin >> n) {
    vector<Course> C;
    for (int i = 0; i < n; ++i) {
      cin >> L >> R;
      C.push_back(Course(L, R, i + 1, 0));
    }
    vector<int> res;
    res = s.schedule(C);
    cout << res.size() << endl;
    if (!res.empty()) {
      for (auto n : res) cout << n << ' ';
      cout << endl;
    }
  }
}
