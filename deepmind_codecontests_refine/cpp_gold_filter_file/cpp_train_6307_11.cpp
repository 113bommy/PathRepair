#include <bits/stdc++.h>
using namespace std;
struct l {
  int i;
  int type;
};
vector<int> dp1, st1, dp2, st2, lk1, lk2;
queue<l> q;
int main() {
  int n, k1, k2;
  cin >> n;
  cin >> k1;
  for (int i = 0; i < k1; i++) {
    int a;
    cin >> a;
    lk1.push_back(a);
  }
  cin >> k2;
  for (int i = 0; i < k2; i++) {
    int a;
    cin >> a;
    lk2.push_back(a);
  }
  dp1.resize(n, k1);
  st1.resize(n, 0);
  dp2.resize(n, k2);
  st2.resize(n, 0);
  st1[0] = 2;
  st2[0] = 2;
  q.push({0, 1});
  q.push({0, 2});
  while (q.size() > 0) {
    l b = q.front();
    q.pop();
    if (b.type == 1) {
      if (st1[b.i] == 1) {
        for (auto i : lk2) {
          int pos = (n + b.i - i) % n;
          dp2[pos]--;
          if (dp2[pos] == 0 && st2[pos] == 0) {
            q.push({pos, 2});
            st2[pos] = 2;
          }
        }
      } else if (st1[b.i] == 2) {
        for (auto i : lk2) {
          int pos = (n + b.i - i) % n;
          if (st2[pos] == 0) {
            q.push({pos, 2});
            st2[pos] = 1;
          }
        }
      }
    } else {
      if (st2[b.i] == 1) {
        for (auto i : lk1) {
          int pos = (n + b.i - i) % n;
          dp1[pos]--;
          if (dp1[pos] == 0 && st1[pos] == 0) {
            q.push({pos, 1});
            st1[pos] = 2;
          }
        }
      } else if (st2[b.i] == 2) {
        for (auto i : lk1) {
          int pos = (n + b.i - i) % n;
          if (st1[pos] == 0) {
            q.push({pos, 1});
            st1[pos] = 1;
          }
        }
      }
    }
  }
  for (int i = 1; i < n; i++) {
    if (st1[i] == 2) {
      cout << "Lose ";
    } else if (st1[i] == 0) {
      cout << "Loop ";
    } else {
      cout << "Win ";
    }
  }
  cout << "\n";
  for (int i = 1; i < n; i++) {
    if (st2[i] == 2) {
      cout << "Lose ";
    } else if (st2[i] == 0) {
      cout << "Loop ";
    } else {
      cout << "Win ";
    }
  }
  cout << "\n";
}
