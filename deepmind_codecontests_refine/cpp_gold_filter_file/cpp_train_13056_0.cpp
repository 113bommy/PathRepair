#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int mxb = b;
  pair<pair<int, int>, int> sk[a + 1];
  for (int i = 0; i < a; i++) {
    sk[i].second = i;
    cin >> sk[i].first.first >> sk[i].first.second;
    sk[i].first.first *= 10000;
    swap(sk[i].first.first, sk[i].first.second);
  }
  sort(sk, sk + a);
  int hurt = 0;
  int sec = 0;
  int x = 0;
  pair<int, int> t[a];
  for (int i = 0; i < a; i++) {
    t[i].first = -1;
    t[i].second = sk[i].second;
  }
  int xx = 0;
  while (b > 0) {
    if (b == mxb) xx++;
    if (xx >= 1001) {
      cout << "NO";
      return 0;
    }
    int pbd = b * 1000000 / mxb;
    for (int i = a - 1; i >= 0; i--) {
      if (sk[i].first.second >= pbd && sk[i].first.first > 0) {
        hurt += sk[i].first.first;
        x++;
        t[i].first = sec;
        sk[i].first.first = -100;
        break;
      }
    }
    b = b + c - hurt;
    b = min(mxb, b);
    sec++;
  }
  cout << "YES" << endl << sec << " " << x << endl;
  sort(t, t + a);
  for (int i = 0; i < a; i++) {
    if (t[i].first > -1) {
      cout << t[i].first << " " << t[i].second + 1 << endl;
    }
  }
  return 0;
}
