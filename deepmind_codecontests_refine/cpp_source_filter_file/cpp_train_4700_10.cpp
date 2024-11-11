#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXLog = 20;
int n, k;
int a[MAXN];
int nxt[MAXN];
int sparse[MAXLog + 5][MAXN];
void init() {
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (st.empty() == false && a[st.top()] <= a[i]) st.pop();
    nxt[i] = ((st.empty() == true) ? n : st.top());
    st.push(i);
  }
  for (int i = 0; i < n; i++) sparse[0][i] = nxt[i];
  for (int i = 1; i <= MAXLog; i++) {
    for (int j = 0; j < n; j++) {
      if (sparse[i - 1][j] == n)
        sparse[i][j] = n;
      else
        sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }
}
int getNext(int ind, int steps) {
  int ans = ind;
  for (int i = MAXLog; i >= 0; i--) {
    if (((steps >> i) & 1) == 1) {
      ans = sparse[i][ans];
      if (ans == n) return ans;
    }
  }
  return ans;
}
int getFitting(int ind, int lim) {
  int ans = 0;
  for (int i = MAXLog; i >= 0; i--) {
    if (sparse[i][ind] <= lim) {
      ans += (1 << i);
      ind = sparse[i][ind];
    }
  }
  return ans;
}
int getAns(deque<int> &opt, int lim) {
  int answer = 0, iter = 0;
  ;
  auto it = opt.end();
  it--;
  while (true) {
    answer = max(answer, getFitting(*it, lim));
    iter++;
    if (iter == 5) break;
    if (it == opt.begin())
      break;
    else
      it--;
  }
  return answer + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> output;
  double average = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  init();
  int answer = 0;
  deque<int> opt;
  for (int i = n - 1; i >= n - k; i--) {
    while (opt.empty() == false &&
           getFitting(i, n - 1) >= getFitting(opt.front(), n - 1))
      opt.pop_front();
    opt.push_front(i);
  }
  output.push_back(getAns(opt, n - 1));
  for (int i = n - 2; i >= k - 1; i--) {
    while (opt.empty() == false &&
           getFitting(i - k + 1, i) >= getFitting(opt.front(), i))
      opt.pop_front();
    opt.push_front(i - k + 1);
    while (opt.size() >= 2) {
      auto it1 = opt.end();
      it1--;
      auto it2 = it1;
      it2--;
      if (getFitting(*it2, i) >= getFitting(*it1, i))
        opt.pop_back();
      else
        break;
    }
    average += opt.size();
    output.push_back(getAns(opt, i));
  }
  reverse(output.begin(), output.end());
  for (int x : output) cout << x << " ";
  cout << '\n';
}
