#include <bits/stdc++.h>
using namespace std;
long long ar[6];
set<long long> st = {4, 8, 15, 16, 23, 42};
long long ask(long long i, long long j) {
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  long long res;
  cin >> res;
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long x = ask(0, 1), y = ask(0, 2);
  if (x % 7 == 0) {
    if (y % 7 == 0)
      ar[0] = 42, ar[1] = x / 42, ar[2] = y / 42;
    else
      ar[1] = 42, ar[0] = x / 42, ar[2] = y / ar[0];
  } else if (x % 23 == 0) {
    if (y % 23 == 0)
      ar[0] = 23, ar[1] = x / 23, ar[2] = y / 23;
    else
      ar[1] = 23, ar[0] = x / 23, ar[2] = y / ar[0];
  } else if (x % 5 == 0) {
    if (y % 5 == 0)
      ar[0] = 5, ar[1] = x / 5, ar[2] = y / 5;
    else
      ar[1] = 5, ar[0] = x / 5, ar[2] = y / ar[0];
  } else if (x == 128) {
    if (y % 7 == 0)
      ar[2] = 42, ar[0] = y / 42, ar[1] = x / ar[0];
    else if (y % 23 == 0)
      ar[2] = 23, ar[0] = y / 23, ar[1] = x / ar[0];
    else if (y % 5 == 0)
      ar[2] = 15, ar[0] = y / 15, ar[1] = x / ar[0];
    else if (y == 64)
      ar[2] = 4, ar[0] = 16, ar[1] = 8;
    else if (y == 32)
      ar[2] = 4, ar[0] = 8, ar[1] = 16;
    else
      exit(-1);
  } else if (x == 64) {
    if (y % 7 == 0)
      ar[2] = 42, ar[0] = y / 42, ar[1] = x / ar[0];
    else if (y % 23 == 0)
      ar[2] = 23, ar[0] = y / 23, ar[1] = x / ar[0];
    else if (y % 5 == 0)
      ar[2] = 15, ar[0] = y / 15, ar[1] = x / ar[0];
    else if (y == 128)
      ar[2] = 8, ar[0] = 16, ar[1] = 4;
    else if (y == 32)
      ar[2] = 8, ar[0] = 4, ar[1] = 16;
    else
      exit(-1);
  } else if (x == 32) {
    if (y % 7 == 0)
      ar[2] = 42, ar[0] = y / 42, ar[1] = x / ar[0];
    else if (y % 23 == 0)
      ar[2] = 23, ar[0] = y / 23, ar[1] = x / ar[0];
    else if (y % 5 == 0)
      ar[2] = 15, ar[0] = y / 15, ar[1] = x / ar[0];
    else if (y == 128)
      ar[2] = 16, ar[0] = 8, ar[1] = 4;
    else if (y == 64)
      ar[2] = 16, ar[0] = 4, ar[1] = 8;
    else
      exit(-1);
  } else
    exit(-1);
  x = ask(3, 3);
  for (long long i = 1; i <= x; i++)
    if (i * i == x) {
      ar[3] = i;
      break;
    }
  ar[4] = ask(3, 4) / ar[3];
  for (long long i = 0; i < 5; i++) st.erase(ar[i]);
  assert((long long)st.size());
  ar[5] = *st.begin();
  cout << "! ";
  for (long long i = 0; i < 6; i++) {
    cout << ar[i] << ' ';
    assert(ar[i]);
  }
  cout << endl;
}
