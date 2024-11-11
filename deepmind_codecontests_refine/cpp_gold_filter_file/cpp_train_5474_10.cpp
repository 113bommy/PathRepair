#include <bits/stdc++.h>
using namespace std;
class problem {
 public:
  void idea() {
    input();
    search();
    output();
  }

 private:
  long long num;
  long long **arr;
  long long *result;
  void input() {
    cin >> num;
    arr = new long long *[num];
    for (long long i = 0; i < num; i++) {
      arr[i] = new long long[4];
      for (long long j = 0; j < 4; j++) cin >> arr[i][j];
    }
    result = new long long[num];
  }
  void search() {
    for (long long i = 0; i < num; i++)
      result[i] = subb(arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
  }
  long long subb(long long x, long long y, long long p, long long q) {
    long long a = 0, z = 2000000000, mid = z / 2;
    for (;;) {
      long long temp = smallest(x, y, p, q, mid);
      if (temp == 0)
        return (mid * q - y);
      else if (temp == 1) {
        z = mid;
        mid = (a + z) / 2;
      } else if (temp == -1) {
        a = mid;
        mid = (a + z) / 2;
      }
      if (mid == a) break;
    }
    return -1;
  }
  long long smallest(long long x, long long y, long long p, long long q,
                     long long mid) {
    long long A = (mid * p), B = (mid * q);
    long long a = ((mid - 1) * p), b = ((mid - 1) * q);
    if ((B >= y) && (A >= x) && ((B - y) >= (A - x))) {
      if ((b >= y) && (a >= x) && ((b - y) >= (a - x)))
        return 1;
      else
        return 0;
    } else
      return -1;
  }
  void output() {
    for (long long i = 0; i < num; i++) cout << result[i] << endl;
  }
};
int main() {
  problem test;
  test.idea();
  return 0;
}
