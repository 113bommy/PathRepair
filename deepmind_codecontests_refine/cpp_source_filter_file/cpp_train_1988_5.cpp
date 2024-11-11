#include <bits/stdc++.h>
using namespace std;
int n;
int query(int pos) {
  cout << "? " << pos << '\n';
  fflush(stdout);
  int one;
  cin >> one;
  cout << "? " << (pos - 1 + n / 2) % n + 1 << '\n';
  fflush(stdout);
  int two;
  cin >> two;
  return one - two;
}
int main() {
  cin >> n;
  int res = query(1);
  if (((res % 2) + 2) % 2 == 1) {
    cout << "! -1\n";
    fflush(stdout);
    return 0;
  }
  if (res == 0) {
    cout << "! 1\n";
    fflush(stdout);
    return 0;
  }
  int start, end;
  if (res < 0) {
    start = 1;
    end = 1 + n / 2;
  } else {
    start = 1 + n / 2;
    end = 1;
  }
  while (start + 1 < end) {
    int mid = (start + end) / 2;
    res = query(mid);
    if (res == 0) {
      cout << "! " << mid << '\n';
      fflush(stdout);
      return 0;
    }
    if (res < 0) {
      start = mid;
    } else
      end = mid;
  }
  res = query(start);
  if (res == 0) {
    cout << "! " << start << '\n';
    fflush(stdout);
    return 0;
  }
  cout << "! " << end << '\n';
  fflush(stdout);
  return 0;
}
