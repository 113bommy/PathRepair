#include <bits/stdc++.h>
using namespace std;
template <class T>
void printQueue(T& q) {
  while (!q.empty()) {
    cout << q.top() << endl;
    q.pop();
  }
}
long long power(long long a, long long b) {
  long long r = 1;
  while (b != 0) {
    if (b % 2 != 0) {
      r = r * a;
    }
    a = a * a;
    b = b / 2;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    stack<int> ast;
    ast.push(s[0] - 96);
    for (int i = 1; i < n; i++) {
      if (!ast.empty()) {
        int k = ast.top();
        if (k == (s[i] - 96)) {
          ast.pop();
          cnt += 1;
        } else {
          ast.push(s[i] - 96);
        }
      } else {
        ast.push(s[0] - 96);
      }
    }
    if (cnt % 2 == 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}
