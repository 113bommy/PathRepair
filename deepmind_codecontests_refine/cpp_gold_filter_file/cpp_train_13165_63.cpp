#include <bits/stdc++.h>
using namespace std;
using namespace std;
template <typename T>
string toString(T t) {
  stringstream ss;
  ss << t;
  return ss.str();
}
vector<set<int> > d = {{0, 1, 2, 3, 4, 5}, {2, 3},       {1, 2, 4, 5, 6},
                       {1, 2, 3, 4, 6},    {0, 2, 3, 6}, {0, 1, 3, 4, 6},
                       {0, 1, 3, 4, 5, 6}, {1, 2, 3},    {0, 1, 2, 3, 4, 5, 6},
                       {0, 1, 2, 3, 4, 6}};
int solve(int a) {
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    int cnt = 0;
    for (int na : d[a]) {
      cnt += d[i].count(na) == 0;
    }
    if (cnt == 0) {
      ans++;
    }
  }
  return ans;
}
int main() {
  char a, b;
  cin >> a >> b;
  cout << solve(a - '0') * solve(b - '0') << endl;
  return 0;
}
