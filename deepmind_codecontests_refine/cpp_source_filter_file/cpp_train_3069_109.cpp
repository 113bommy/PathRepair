#include <bits/stdc++.h>
long long int height[200007] = {0};
using namespace std;
bool sortdem(const tuple<long long int, long long int, long long int> &a,
             const tuple<long long int, long long int, long long int> &b) {
  if (get<1>(a) > get<1>(b))
    return true;
  else if (get<1>(a) < get<1>(b))
    return false;
  else if (get<0>(a) < get<0>(b))
    return true;
  else
    return false;
}
long long int solve(long long int c) {
  long long int sum = 0;
  while (c) {
    sum += c;
    c /= 2;
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int Q = 0, R = 0, B = 0, N = 0, P = 0, K = 0, q = 0, r = 0, b = 0,
                n = 0, p = 0, k = 0;
  char a[8][8];
  for (long long int i = 0; i < 8; i++) {
    for (long long int j = 0; j < 8; j++) {
      cin >> a[i][j];
      if (a[i][j] != '.') {
        switch (a[i][j]) {
          case 'Q':
            Q++;
            break;
          case 'R':
            R++;
            break;
          case 'B':
            B++;
            break;
          case 'N':
            N++;
            break;
          case 'P':
            P++;
            break;
          case 'K':
            K++;
            break;
          case 'q':
            q++;
            break;
          case 'r':
            r++;
            break;
          case 'b':
            b++;
            break;
          case 'n':
            n++;
            break;
          case 'p':
            p++;
            break;
          case 'k':
            k++;
            break;
        }
      }
    }
  }
  if (9 * Q + 5 * R + 3 * B + 3 * K + P < 9 * q + 5 * r + 3 * b + 3 * k + p)
    cout << "Black" << endl;
  else if (9 * Q + 5 * R + 3 * B + 3 * K + P ==
           9 * q + 5 * r + 3 * b + 3 * k + p)
    cout << "Draw" << endl;
  else
    cout << "White" << endl;
  return 0;
}
