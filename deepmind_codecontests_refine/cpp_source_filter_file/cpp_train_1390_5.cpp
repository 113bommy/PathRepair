#include <bits/stdc++.h>
using namespace std;
struct team {
  string nam;
  int pt, sc, ms;
};
int n;
team t[50];
void add(const string &s, int a, int b) {
  for (int i = 0; i < n; i++) {
    if (t[i].nam == s) {
      if (a > b) {
        t[i].pt += 3;
      } else if (a == b) {
        t[i].pt += 1;
      }
      t[i].sc += a;
      t[i].ms += b;
      break;
    }
  }
}
bool less1(const team &a, const team &b) {
  if (a.pt != b.pt) {
    return a.pt > b.pt;
  } else if (a.sc - a.ms != b.sc - b.ms) {
    return a.sc - a.ms > b.sc - b.ms;
  } else {
    return a.nam < b.nam;
  }
}
bool less2(const team &a, const team &b) { return a.nam < b.nam; }
int main() {
  string a, b;
  int c, d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i].nam;
  }
  cin.ignore();
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    getline(cin, a, '-');
    getline(cin, b, ' ');
    scanf("%d:%d", &c, &d);
    cin.ignore();
    add(a, c, d);
    add(b, d, c);
  }
  sort(t, t + n, less1);
  sort(t, t + n / 2, less2);
  for (int i = 0; i < n / 2; i++) {
    cout << t[i].nam << endl;
  }
  return 0;
}
