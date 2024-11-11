#include <bits/stdc++.h>
using namespace std;
int a, b, c;
vector<int> v;
int H, M, S;
set<pair<int, int> > s;
int ans[30000];
int main() {
  cin >> a >> b >> c;
  for (int i = 0; i < a; ++i) {
    scanf("%d:%d:%d", &H, &M, &S);
    v.push_back(H * 3600 + M * 60 + S);
  }
  int n = 0;
  int cnt = 1;
  s.clear();
  bool flag = false;
  for (int i = 0; i < v.size(); ++i) {
    while (!s.empty() && s.begin()->first < v[i]) {
      --n;
      s.erase(s.begin());
    }
    ++n;
    if (n <= b) {
      ans[i] = cnt++;
      s.insert(make_pair(v[i] + c, i));
    } else {
      ans[i] = cnt - 1;
      --n;
      s.erase(make_pair(v[i - 1] + c, i - 1));
      s.insert(make_pair(v[i] + c, i));
    }
    if (n == b) {
      flag = true;
    }
  }
  if (!flag) {
    cout << "No solution" << endl;
    return 0;
  }
  cout << cnt - 1 << "\n";
  for (int i = 0; i < a; ++i) cout << ans[i] << "\n";
}
