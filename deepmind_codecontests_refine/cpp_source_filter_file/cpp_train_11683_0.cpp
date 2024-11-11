#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<string, int>, vector<pair<string, int>>,
               greater<pair<string, int>>>
    heap;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    string p = "";
    p = p + s[i];
    heap.push(make_pair(p, i));
  }
  string res;
  while (!heap.empty()) {
    string res = heap.top().first;
    int pos = heap.top().second;
    heap.pop();
    k--;
    if (k == 0) break;
    if (pos + 1 < n) heap.push(make_pair(res + s[pos + 1], pos + 1));
  }
  if (k > 0) {
    cout << "No such line.";
    return 0;
  }
  cout << res << '\n';
}
