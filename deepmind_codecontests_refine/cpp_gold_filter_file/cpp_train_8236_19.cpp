#include <bits/stdc++.h>
using namespace std;
struct sub {
  int l, r;
  long long total, leftB, rightB;
  long long difL, difR;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a;
  cin >> n >> a;
  long long MAX = 0;
  vector<sub> data(n);
  for (int i = 0; i < (n); i++) {
    int d, c;
    cin >> d >> c;
    data[i] = {i, i, a - c, a - c, a - c, d, d};
    MAX = max({MAX, a - (long long)c});
  }
  vector<pair<long long, int>> difPointers;
  for (int i = 0; i < (n - 1); i++) {
    difPointers.push_back(
        {(data[i + 1].difL - data[i].difL) * (data[i + 1].difL - data[i].difL),
         i});
  }
  sort(difPointers.begin(), difPointers.end());
  for (auto p : difPointers) {
    sub s1 = data[p.second];
    sub s2 = data[p.second + 1];
    long long total = s1.total + s2.total;
    int l = s1.l;
    int r = s2.r;
    long long leftB = max({s1.leftB, s1.total + s2.leftB});
    long long rightB = max({s2.rightB, s2.total + s1.rightB});
    MAX = max({MAX, -p.first + s1.rightB + s2.leftB});
    sub nova{l, r, total, leftB, rightB, -1, -1};
    data[l] = nova;
    data[r] = nova;
  }
  cout << MAX << endl;
}
