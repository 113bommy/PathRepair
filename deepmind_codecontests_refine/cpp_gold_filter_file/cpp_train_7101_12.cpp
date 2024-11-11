#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 * 1000;
int d[MAX + 10];
string s;
struct cmp {
  bool operator()(int a, int b) {
    if (s[a + min(d[a], d[b])] == s[b + min(d[a], d[b])]) return d[a] > d[b];
    return s[a + min(d[a], d[b])] > s[b + min(d[a], d[b])];
  }
};
priority_queue<int, vector<int>, cmp> heap;
int main() {
  int k;
  cin >> s >> k;
  for (int i = 0; i < (int)s.size(); i++) heap.push(i);
  for (int i = 1; i < k; i++) {
    if (heap.empty()) {
      cout << "No such line." << endl;
      return 0;
    }
    int tmp = heap.top();
    heap.pop();
    d[tmp]++;
    if (tmp + d[tmp] < (int)s.size()) heap.push(tmp);
  }
  if (heap.empty()) {
    cout << "No such line." << endl;
    return 0;
  }
  for (int i = heap.top(); i <= heap.top() + d[heap.top()]; i++) cout << s[i];
  cout << endl;
  while (cin >> k)
    ;
  return 0;
}
