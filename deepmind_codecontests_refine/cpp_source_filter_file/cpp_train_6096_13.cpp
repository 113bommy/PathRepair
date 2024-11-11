#include <bits/stdc++.h>
using namespace std;
const int64_t r = 1024 * 64;
int main() {
  int64_t n;
  cin >> n;
  int64_t l1, r1, u1, d1, l2, r2, u2, d2;
  int64_t t = r;
  int64_t ch = 0;
  for (; t != 1;) {
    cout << "? " << min(ch + t / 2, n) << ' ' << 1 << ' ' << min(r, n) << ' '
         << min(r, n) << endl;
    int c;
    scanf("%d", &c);
    if (c == 2) {
      ch += t / 2;
      if (n <= ch) {
        ch = n;
        break;
      }
    }
    t /= 2;
  }
  l1 = ch;
  t = r;
  ch = 0;
  for (; t != 1;) {
    cout << "? " << min(ch + t / 2, n) << ' ' << 1 << ' ' << min(r, n) << ' '
         << min(r, n) << endl;
    int c;
    scanf("%d", &c);
    if (c > 0) {
      ch += t / 2;
      if (n <= ch) {
        ch = n;
        break;
      }
    }
    t /= 2;
  }
  l2 = ch;
  t = r;
  ch = r;
  for (; t != 1;) {
    cout << "? " << 1 << ' ' << 1 << ' ' << min(ch - t / 2, n) << ' '
         << min(r, n) << endl;
    int c;
    scanf("%d", &c);
    if (c == 2) ch -= t / 2;
    t /= 2;
  }
  r1 = min(ch, n);
  t = r;
  ch = r;
  for (; t != 1;) {
    cout << "? " << 1 << ' ' << 1 << ' ' << min(ch - t / 2, n) << ' '
         << min(r, n) << endl;
    int c;
    scanf("%d", &c);
    if (c > 0) ch -= t / 2;
    t /= 2;
  }
  r2 = min(ch, n);
  t = r;
  ch = 0;
  for (; t != 1;) {
    cout << "? " << 1 << ' ' << min(ch + t / 2, n) << ' ' << min(r, n) << ' '
         << min(r, n) << endl;
    int c;
    scanf("%d", &c);
    if (c == 2) {
      ch += t / 2;
      if (n <= ch) {
        ch = n;
        break;
      }
    }
    t /= 2;
  }
  u1 = ch;
  t = r;
  ch = 0;
  for (; t != 1;) {
    cout << "? " << 1 << ' ' << min(ch + t / 2, n) << ' ' << min(r, n) << ' '
         << min(r, n) << endl;
    int c;
    scanf("%d", &c);
    if (c > 0) {
      ch += t / 2;
      if (n <= ch) {
        ch = n;
        break;
      }
    }
    t /= 2;
  }
  u2 = ch;
  t = r;
  ch = r;
  for (; t != 1;) {
    cout << "? " << 1 << ' ' << 1 << ' ' << min(r, n) << ' '
         << min(ch - t / 2, n) << endl;
    int c;
    scanf("%d", &c);
    if (c == 2) ch -= t / 2;
    t /= 2;
  }
  d1 = min(ch, n);
  t = r;
  ch = r;
  for (; t != 1;) {
    cout << "? " << 1 << ' ' << 1 << ' ' << min(r, n) << ' '
         << min(ch - t / 2, n) << endl;
    int c;
    scanf("%d", &c);
    if (c > 0) ch -= t / 2;
    t /= 2;
  }
  d2 = min(ch, n);
  if (l2 <= r2) {
    cout << "? " << l2 << ' ' << 1 << ' ' << r2 << ' ' << min(r, n) << endl;
    cin >> ch;
  } else
    ch = 0;
  if (ch == 0) swap(l1, l2);
  if (u2 <= d2) {
    cout << "? " << 1 << ' ' << u2 << ' ' << min(r, n) << ' ' << d2 << endl;
    cin >> ch;
  } else
    ch = 0;
  if (ch == 0) swap(d1, d2);
  int64_t bb = 0;
  cout << "? " << l1 << ' ' << u2 << ' ' << r1 << ' ' << d2 << endl;
  cin >> ch;
  if (ch == 1) ++bb;
  cout << "? " << l2 << ' ' << u1 << ' ' << r2 << ' ' << d1 << endl;
  cin >> ch;
  if (ch == 1) ++bb;
  if (bb == 2) {
    swap(u1, u2);
    swap(d1, d2);
  }
  cout << "! " << l1 << ' ' << u1 << ' ' << r1 << ' ' << d1 << ' ' << l2 << ' '
       << u2 << ' ' << r2 << ' ' << d2 << endl;
  return 0;
}
