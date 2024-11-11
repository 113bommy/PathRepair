#include <bits/stdc++.h>
using namespace std;
vector<long long> tomb;
int main() {
  int n;
  cin >> n;
  bool over = false;
  long long hatar = UINT_MAX;
  for (int x = 0; n > x && !over; ++x) {
    string a;
    cin >> a;
    if (a == "for") {
      int b;
      cin >> b;
      tomb.push_back(-b);
    } else if (a == "add") {
      tomb.push_back(1);
    } else if (a == "end") {
      long long szamolo = 0;
      while (tomb.back() > 0) {
        szamolo += tomb.back();
        tomb.pop_back();
      }
      long long ww = szamolo * tomb.back() * -1;
      if (ww <= hatar) {
        tomb.back() = ww;
      } else {
        over = true;
      }
    }
  }
  long long c = 0;
  for (int x = 0; tomb.size() > x && !over; ++x) {
    if (c + tomb[x] <= hatar) {
      c += tomb[x];
    } else {
      over = true;
    }
  }
  if (over) {
    cout << "OVERFLOW!!!" << endl;
  } else {
    cout << c << endl;
  }
}
