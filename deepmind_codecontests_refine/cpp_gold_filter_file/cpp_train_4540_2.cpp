#include <bits/stdc++.h>
using namespace std;
int main() {
  priority_queue<int, vector<int>, greater<int> > q;
  bool srt = true;
  int n, cnt = 1, x, tpp = -1, res = 0, tpp_ = -1, qu[311111], qu_pos[311111],
         ind = 1;
  string ch;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> ch;
    if (ch == "add") cin >> x;
    if (ch == "add") {
      q.push(x);
      tpp_ = x;
      if (x > q.top() && srt) srt = false;
      qu[ind] = x;
      qu_pos[x] = ind++;
    } else {
      q.pop();
      if (cnt != tpp_) {
        res++;
        if (!q.empty())
          tpp_ = q.top();
        else
          tpp_ = -1;
        srt = true;
      } else {
        if (!srt && !q.empty())
          tpp_ = qu[qu_pos[cnt] - 1];
        else if (!q.empty() && srt) {
          tpp_ = q.top();
        } else
          tpp_ = -1;
      }
      cnt++;
    }
  }
  cout << res << endl;
  return 0;
}
