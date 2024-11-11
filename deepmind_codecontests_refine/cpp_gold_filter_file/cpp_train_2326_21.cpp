#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
double sqr(double a) { return a * a; }
struct Node {
  vector<int> nbr;
  int used;
  int p1, p2;
  int init, goal;
  Node() {
    p1 = p2 = 0;
    used = 0;
  }
};
int m;
int mpower(int a, int b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    int c = mpower(a, b / 2) % m;
    return c * c % m;
  } else {
    return a * mpower(a, b - 1) % m;
  }
}
int check(int a, int p) {
  if ((mpower(a, p - 1) - 1) % p == 0) {
    for (int i = 1; i <= p - 2; ++i) {
      int c = mpower(a, i) - 1;
      if (c % p == 0) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}
bool check(vector<vector<long long int> >& arr, int r) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < arr[0].size(); ++j) {
      if (arr[i][j] != arr[2 * r - i - 1][j]) return false;
    }
  }
  return true;
}
void calc(map<long long int, long long int>& s, long long int a,
          long long int d) {
  if (a == 0) return;
  if (s.count(a)) {
    if (s[a] >= d) return;
    s[a] = min(s[a], d);
  } else {
    s[a] = d;
  }
  if (a % 2 == 0) {
    calc(s, a / 2, d + 1);
  }
  if (a % 3 == 0) {
    calc(s, a / 3, d + 1);
  }
  if (a % 5 == 0) {
    calc(s, a / 5, d + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);
  long long int d, n;
  cin >> d >> n;
  long long int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    long long int a;
    cin >> a;
    ans += d - a;
  }
  cout << ans;
  return 0;
}
