#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const int maxNum = 1000;
int field[maxNum][maxNum];
vector<pair<int, int> > tmp;
void calc(int n, int m) {
  if (n == 0 || m == 0) {
    if (n == 1 || m == 1) {
      int x = tmp.size();
      tmp[x - 1].second--;
      calc(1, 1);
      return;
    } else {
      tmp.clear();
      tmp.push_back(make_pair(-1, -1));
      return;
    }
  }
  if (n < m) {
    tmp.push_back(make_pair(0, m / n));
    calc(n, m % n);
    return;
  }
  if (n > m) {
    tmp.push_back(make_pair(1, n / m));
    calc(n % m, m);
    return;
  }
  if (n == 1 || m == 1) {
    int x = tmp.size();
    if (tmp[x - 1].first == 1) {
      for (int i = 0; i < x; i++) {
        if (tmp[i].first == 0)
          tmp[i].first = 1;
        else
          tmp[i].first = 0;
      }
    }
    tmp.push_back(make_pair(1, 1));
    return;
  }
  if (n == m) {
    tmp.clear();
    tmp.push_back(make_pair(-1, -1));
    return;
  }
}
int main() {
  int n, r;
  cin >> n >> r;
  vector<pair<int, int> > ans;
  int inf = 10000000;
  int best = inf;
  for (int i = 1; i < r; i++) {
    tmp.clear();
    calc(i, r);
    if (tmp[0].first != -1) {
      int sum = 0;
      int x = tmp.size();
      for (int i = 0; i < x; i++) {
        sum += tmp[i].second;
      }
      if (sum < n) {
        tmp.push_back(make_pair(0, n - sum));
      }
      if (sum == n) {
        int score = n - tmp.size();
        if (score < best) {
          ans = tmp;
          best = score;
        }
      }
    }
  }
  if (r == 1) {
    if (n == 1)
      cout << "0" << endl << "T" << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  } else if (best == inf)
    cout << "IMPOSSIBLE" << endl;
  else {
    cout << best << endl;
    int x = ans.size();
    for (int i = x - 1; i >= 0; i--) {
      for (int j = 0; j < ans[i].second; j++) {
        if (ans[i].first == 1)
          printf("T");
        else
          printf("B");
      }
    }
    printf("\n");
  }
  return 0;
}
