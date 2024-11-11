#include <bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long x, unsigned long long y) {
  unsigned long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, i = 0, j, x, y, z, start, end, mid;
    cin >> n;
    start = 1;
    end = 2000000000;
    y = 1;
    while (start <= end) {
      mid = (start + end) / 2;
      x = mid * (mid + 1) / 2;
      j = 10;
      while (j <= mid) {
        long long a;
        a = (mid - j + 1);
        x += (a * (a + 1)) / 2;
        j *= 10;
      }
      if (x == n) {
        y = mid;
        break;
      } else if (x < n)
        start = mid + 1, y = mid, z = x;
      else
        end = mid - 1;
    }
    if (x == n) {
      x = (y % 10);
      cout << x << "\n";
    } else {
      x = n - z;
      j = 9;
      i = 1;
      while (x - j * i > 0) {
        x -= (j * i);
        j *= 10;
        i++;
      }
      y = x % i;
      x = ceil(x / double(i));
      x--;
      j = power(10, i - 1);
      x += j;
      vector<int> temp;
      while (x != 0) {
        temp.push_back(x % 10);
        x -= (x % 10);
        x /= 10;
      }
      reverse(temp.begin(), temp.end());
      for (j = 0; j < temp.size(); j++) {
        if (y == (j + 1) % i) cout << temp[j] << "\n";
      }
    }
  }
  return 0;
}
