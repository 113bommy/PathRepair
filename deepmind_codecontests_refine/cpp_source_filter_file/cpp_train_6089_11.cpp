#include <bits/stdc++.h>
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1070000000LL;
const long long MOD = 1000000007LL;
using namespace std;
int n, k, a0, a1;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  string name1 = "Stannis", name2 = "Daenerys";
  cin >> n >> k;
  for (long long i = (long long)(0); i < (long long)(n); i++) {
    int a;
    cin >> a;
    if (a % 2)
      a1++;
    else
      a0++;
  }
  int t = n - k;
  int p1 = (t + 1) / 2, p2 = t / 2;
  if (t == 0) {
    return cout << (p1 % 2 ? name1 : name2) << endl, 0;
  }
  if (t % 2 == 1) {
    if (a0 < a1) {
      if (p2 < a0) {
        return cout << name1 << endl, 0;
      } else {
        int remain1 = k;
        if (remain1 % 2 == 1) {
          return cout << name1 << endl, 0;
        } else {
          return cout << name2 << endl, 0;
        }
      }
    } else if (a1 < a0) {
      if (p2 < a1) {
        return cout << name1 << endl, 0;
      } else {
        return cout << name2 << endl, 0;
      }
    } else {
      return cout << name1 << endl, 0;
    }
  } else {
    if (a0 < a1) {
      if (p1 < a0) {
        return cout << name2 << endl, 0;
      } else {
        int remain1 = k;
        if (remain1 % 2 == 0) {
          return cout << name2 << endl, 0;
        } else {
          return cout << name1 << endl, 0;
        }
      }
    } else if (a1 < a0) {
      if (p1 < a1) {
        return cout << name2 << endl, 0;
      } else {
        return cout << name2 << endl, 0;
      }
    } else {
      return cout << name2 << endl, 0;
    }
  }
}
