#include <bits/stdc++.h>
using namespace std;
void cline() { cout << '\n'; }
template <typename T, typename... V>
void cline(T t, V... v) {
  cout << t;
  if (sizeof...(v)) cout << ' ';
  cline(v...);
}
void cspc() { cout << ' '; }
template <typename T, typename... V>
void cspc(T t, V... v) {
  cout << t;
  if (sizeof...(v)) cout << ' ';
  cspc(v...);
}
const int N = 2e6 + 4;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int h, m;
  char c;
  cin >> h >> c >> m;
  int ex;
  cin >> ex;
  h = (h + (m + ex) / 60) % 60;
  m = (m + ex) % 60;
  if (h == 24) {
    cout << "00";
  } else {
    cout << setw(2) << setfill('0') << h;
  }
  cout << ":";
  cout << setw(2) << setfill('0') << m;
  return 0;
}
