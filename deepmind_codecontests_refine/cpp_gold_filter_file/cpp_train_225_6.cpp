#include <bits/stdc++.h>
using namespace std;
long long A, B;
struct DIEM {
  long long x, y;
  void init_value() { cin >> x >> y; }
  void move_45() {
    int x1 = x, y1 = y;
    x = x1 + y1;
    y = x1 - y1;
  }
  void xuat() { cout << x << ' ' << y << endl; }
};
DIEM st, first;
void file() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void init() {
  cin >> A >> B;
  st.init_value();
  first.init_value();
}
void process_data() {
  st.move_45();
  first.move_45();
  A *= 2;
  B *= 2;
}
long long Calc(long long s, long long mod) { return s / mod + (s > 0); }
void solve() {
  long long x1 = Calc(st.x, A);
  long long x2 = Calc(first.x, A);
  long long y1 = Calc(st.y, B);
  long long y2 = Calc(first.y, B);
  cout << max(abs(x1 - x2), abs(y1 - y2)) << endl;
}
int main() {
  file();
  init();
  process_data();
  solve();
}
