#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
const int M = 1000000007;
const double PI = atan(1) * 4;
const int oo = 1000000000;
int n, v[N], x, y, id;
long long bst;
vector<int> g;
multiset<int> st;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &v[i]);
    int d = v[i] - i;
    bst += abs(d);
    if (d > 0)
      ++x;
    else
      ++y;
    if (d > 0) st.insert(d);
  }
  long long cur = bst;
  for (int i = 1; i < n; ++i) {
    while (!st.empty() && *st.rbegin() - i < 0) {
      --x;
      ++y;
      st.erase(--st.end());
    }
    int d = v[n - i + 1], idx = n + 1 - i;
    int p = d - idx;
    int subt = min(max(0, p), n - idx), add = n - idx - subt;
    if (p - i >= 0) {
      st.erase(st.find(p));
      --x;
    } else
      --y;
    int off = d - 1;
    cur = cur + y - x - add + subt + off - abs(p);
    if (d - 1 > 0) {
      st.insert(d - 1 + i);
      ++x;
    } else
      ++y;
    if (cur < bst) {
      bst = cur;
      id = i;
    }
  }
  cout << bst << " " << id << endl;
}
