#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
int main() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  if (n % 2 == 1) {
    puts(":(");
    return 0;
  }
  if (s[0] == ')') {
    puts(":(");
    return 0;
  } else if (s[0] == '?') {
    s[0] = '(';
  }
  int cntl = 0;
  queue<int> q;
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == '?') {
      q.push(i);
    } else if (s[i] == '(') {
      cntl++;
    } else if (s[i] == ')') {
      if (cntl > 0) {
        cntl--;
      } else if (cntl == 0 && !q.empty()) {
        int now = q.front();
        q.pop();
        s[now] = '(';
      } else {
        puts(":(");
        return 0;
      }
    }
  }
  if (s[n - 1] == '?') s[n - 1] = ')';
  int len = q.size();
  int cnt = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    cnt++;
    if (cnt <= len / 2) {
      s[now] = '(';
    } else
      s[now] = ')';
  }
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      cnt++;
    } else {
      cnt--;
    }
    if (cnt <= 0 && i < n - 1) {
      puts(":(");
      return 0;
    }
  }
  if (cnt == 0) {
    cout << s << endl;
  } else {
    puts(":(");
  }
  return 0;
}
