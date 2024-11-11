#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int start, end;
  int count;
  Node(int s = 0, int e = 0, int c = 0) : start(s), end(e), count(c) {}
};
class StackNode {
 public:
  char first;
  int second;
  int third;
};
StackNode makenode(char a, int b, int c) {
  StackNode t;
  t.first = a;
  t.second = b;
  t.third = c;
  return t;
}
bool operator<(const Node &a, const Node &b) { return a.count < b.count; }
bool cmp(const Node &a, const Node &b) { return a.end < b.end; }
int main() {
  string s;
  stack<StackNode> S;
  vector<Node> v;
  vector<int> dp;
  cin >> s;
  int left = 0;
  Node cur;
  dp.resize(s.length());
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '[') left++;
    if (s[i] == '[' || s[i] == '(') {
      S.push(makenode(s[i], i, left));
    } else if (s[i] == ']') {
      if (S.empty()) continue;
      char c = S.top().first;
      if (c == '[') {
        StackNode p = S.top();
        S.pop();
        cur.count = left - p.third + 1;
        cur.start = p.second;
        cur.end = i;
        v.push_back(cur);
      }
      if (c == '(') {
        while (!S.empty()) S.pop();
      }
    } else if (s[i] == ')') {
      if (S.empty()) continue;
      char c = S.top().first;
      if (c == '[') {
        while (!S.empty()) S.pop();
      }
      if (c == '(') {
        StackNode p = S.top();
        S.pop();
        cur.count = left - p.third;
        cur.start = p.second;
        cur.end = i;
        v.push_back(cur);
      }
    }
  }
  vector<int> in(s.length());
  sort(v.begin(), v.end(), cmp);
  fill(dp.begin(), dp.end(), 0);
  for (int i = 0; i < in.size(); i++) in[i] = -1;
  for (int i = 0; i < v.size(); i++) {
    int s = v[i].start, t = v[i].end;
    if (s == 0) {
      if (dp[t] < v[i].count) {
        dp[t] = v[i].count;
        in[t] = 0;
      }
    } else {
      if (dp[t] < dp[s - 1] + v[i].count) {
        dp[t] = dp[s - 1] + v[i].count;
        if (in[s - 1] == -1)
          in[t] = s;
        else
          in[t] = in[s - 1] + 1;
      }
    }
  }
  vector<int>::iterator it = max_element(dp.begin(), dp.end());
  if (it == dp.end() || *it == 0)
    cout << "0\n\n";
  else {
    cout << *it << endl;
    int p = it - dp.begin();
    for (int i = in[p]; i <= p; i++) cout << s[i];
    cout << endl;
  }
  return 0;
}
