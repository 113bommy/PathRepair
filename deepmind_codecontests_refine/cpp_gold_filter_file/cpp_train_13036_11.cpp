#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int m[501][3];
  queue<int> q;
  for (int i = 1; i <= a; i++) {
    cin >> m[i][0] >> m[i][1] >> m[i][2];
    if (m[i][0] >= 4 && m[i][1] >= 4 && m[i][2] >= 4) {
      q.push(7);
      continue;
    } else if (m[i][0] == 3 && m[i][1] >= 3 && m[i][2] >= 3) {
      q.push(6);
      continue;
    } else if (m[i][0] >= 3 && m[i][1] == 3 && m[i][2] >= 3) {
      q.push(6);
      continue;
    } else if (m[i][0] >= 3 && m[i][1] >= 3 && m[i][2] == 3) {
      q.push(6);
      continue;
    } else if (m[i][0] == 2 && m[i][1] >= 3 && m[i][2] >= 3) {
      q.push(5);
      continue;
    } else if (m[i][0] >= 3 && m[i][1] == 2 && m[i][2] >= 3) {
      q.push(5);
      continue;
    } else if (m[i][0] >= 3 && m[i][1] >= 3 && m[i][2] == 2) {
      q.push(5);
      continue;
    } else if (m[i][0] == 2 && m[i][1] == 2 && m[i][2] >= 3) {
      q.push(5);
      continue;
    } else if (m[i][0] >= 3 && m[i][1] == 2 && m[i][2] == 2) {
      q.push(5);
      continue;
    } else if (m[i][0] == 2 && m[i][1] >= 3 && m[i][2] == 2) {
      q.push(5);
      continue;
    } else if (m[i][0] == 2 && m[i][1] == 2 && m[i][2] == 2) {
      q.push(4);
      continue;
    } else if (m[i][0] >= 2 && m[i][1] >= 2 && m[i][2] == 1) {
      q.push(4);
      continue;
    } else if (m[i][0] == 1 && m[i][1] >= 2 && m[i][2] >= 2) {
      q.push(4);
      continue;
    } else if (m[i][0] >= 2 && m[i][1] == 1 && m[i][2] >= 2) {
      q.push(4);
      continue;
    } else if (m[i][0] >= 1 && m[i][1] == 1 && m[i][2] == 1) {
      q.push(3);
      continue;
    } else if (m[i][0] == 1 && m[i][1] == 1 && m[i][2] >= 1) {
      q.push(3);
      continue;
    } else if (m[i][0] == 1 && m[i][1] >= 1 && m[i][2] == 1) {
      q.push(3);
      continue;
    } else if (m[i][0] >= 2 && m[i][1] == 0 && m[i][2] >= 2) {
      q.push(3);
      continue;
    } else if (m[i][0] >= 2 && m[i][1] >= 2 && m[i][2] == 0) {
      q.push(3);
      continue;
    } else if (m[i][0] == 0 && m[i][1] >= 2 && m[i][2] >= 2) {
      q.push(3);
      continue;
    } else if (m[i][0] >= 1 && m[i][1] == 0 && m[i][2] == 1) {
      q.push(2);
      continue;
    } else if (m[i][0] == 1 && m[i][1] >= 1 && m[i][2] == 0) {
      q.push(2);
      continue;
    } else if (m[i][0] == 1 && m[i][1] == 0 && m[i][2] >= 1) {
      q.push(2);
      continue;
    } else if (m[i][0] >= 1 && m[i][1] == 1 && m[i][2] == 0) {
      q.push(2);
      continue;
    } else if (m[i][0] == 0 && m[i][1] >= 1 && m[i][2] == 1) {
      q.push(2);
      continue;
    } else if (m[i][0] == 0 && m[i][1] == 1 && m[i][2] >= 1) {
      q.push(2);
      continue;
    } else if (m[i][0] >= 1 && m[i][1] == 0 && m[i][2] == 0) {
      q.push(1);
      continue;
    } else if (m[i][0] == 0 && m[i][1] >= 1 && m[i][2] == 0) {
      q.push(1);
      continue;
    } else if (m[i][0] == 0 && m[i][1] == 0 && m[i][2] >= 1) {
      q.push(1);
      continue;
    } else if (m[i][0] == 0 && m[i][1] == 0 && m[i][2] == 0) {
      q.push(0);
      continue;
    }
  }
  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }
  return 0;
}
