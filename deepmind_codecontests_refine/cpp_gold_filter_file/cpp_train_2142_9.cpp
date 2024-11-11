#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;
char op;
string s;
void print(char c, int z) {
  int t1 = a / (z + 1), m1 = a % (z + 1);
  int q1 = m1, p1 = (z + 1) - m1;
  int t2 = b / z, m2 = b % z;
  int q2 = m2, p2 = z - m2;
  char g = (c == 'G') ? 'B' : 'G';
  for (int i = 1; i <= z; i++) {
    if (q1) {
      for (int t = 0; t < t1 + 1; t++) printf("%c", c);
      q1--;
    } else {
      for (int t = 0; t < t1; t++) printf("%c", c);
    }
    if (q2) {
      for (int t = 0; t < t2 + 1; t++) printf("%c", g);
      q2--;
    } else {
      for (int t = 0; t < t2; t++) printf("%c", g);
    }
  }
  if (q1) {
    for (int t = 0; t < t1 + 1; t++) printf("%c", c);
    q1--;
  } else {
    for (int t = 0; t < t1; t++) printf("%c", c);
  }
  printf("\n");
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> a >> b;
  if (a > b)
    op = 'G';
  else
    op = 'B';
  if (a < b) swap(a, b);
  if (b == 0) {
    if (n > k)
      cout << "NO" << endl;
    else {
      for (int i = 0; i < n; i++) {
        printf("%c", op);
      }
      printf("\n");
    }
    return 0;
  }
  for (int i = 1; i <= b; i++) {
    int t1 = (a % (i + 1) == 0 ? a / (i + 1) : a / (i + 1) + 1),
        t2 = (b % (i) == 0 ? b / (i) : b / (i) + 1);
    if (t1 <= k && t2 <= k) {
      print(op, i);
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
