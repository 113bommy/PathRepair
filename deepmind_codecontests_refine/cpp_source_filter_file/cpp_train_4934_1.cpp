#include <bits/stdc++.h>
using namespace std;
const int din[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool correct(int d, int m, int y) {
  if (d > 12 || m > 12 || y > 99) return false;
  int dc = din[m - 1];
  if (y % 4 == 0 && m == 2) dc++;
  if (d > dc) return false;
  return true;
}
bool good(int db, int mb, int yb, int df, int mf, int yf) {
  yb += 18;
  if (yb > yf) return false;
  if (yb < yf) return true;
  if (mb > mf) return false;
  if (mb < mf) return true;
  if (db > df) return false;
  return true;
}
int main() {
  int db, mb, yb, df, mf, yf;
  scanf("%d.%d.%d", &df, &mf, &yf);
  scanf("%d.%d.%d", &db, &mb, &yb);
  if (correct(db, mb, yb) && good(db, mb, yb, df, mf, yf)) {
    cout << "YES";
    return 0;
  }
  if (correct(db, yb, mb) && good(db, yb, mb, df, mf, yf)) {
    cout << "YES";
    return 0;
  }
  if (correct(mb, db, yb) && good(mb, db, yb, df, mf, yf)) {
    cout << "YES";
    return 0;
  }
  if (correct(mb, yb, db) && good(mb, yb, db, df, mf, yf)) {
    cout << "YES";
    return 0;
  }
  if (correct(yb, db, mb) && good(yb, db, mb, df, mf, yf)) {
    cout << "YES";
    return 0;
  }
  if (correct(yb, mb, db) && good(yb, mb, db, df, mf, yf)) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
