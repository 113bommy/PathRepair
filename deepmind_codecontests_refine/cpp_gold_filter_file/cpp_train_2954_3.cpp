#include <bits/stdc++.h>
using namespace std;
int grundy[11111111];
bool occ[20];
int getid(long long x) {
  if (x >= 0 && x <= 3) {
    return 0;
  }
  if (x >= 4 && x <= 15) {
    return 1;
  }
  if (x >= 16 && x <= 81) {
    return 2;
  }
  if (x >= 82 && x <= 6724) {
    return 3;
  }
  if (x >= 6725 && x <= 50625) return 4;
  return 5;
}
long long fourthroot(long long x) {
  long long low = 0;
  long long high = 10000;
  while (low < high) {
    long long mid = (low + high) / 2;
    if (mid * mid * mid * mid < x) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}
long long secondroot(long long x) {
  long long low = 0;
  long long high = 10000000;
  while (low < high) {
    long long mid = (low + high + 1) / 2;
    if (mid * mid > x) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  return low;
}
int gs[] = {0, 1, 2, 0, 3, 1};
long long findgrundy(long long x) {
  if (x <= 3) return 0;
  long long low = max(0ll, fourthroot(x));
  long long high = min(x - 1ll, secondroot(x));
  if (low > high) return 0;
  int lowid = getid(low);
  int highid = getid(high);
  bool occ[10];
  for (int i = 0; i < 10; i++) occ[i] = false;
  for (int j = lowid; j <= highid; j++) {
    occ[gs[j]] = true;
  }
  for (int i = 0; i < 10; i++)
    if (!occ[i]) return i;
}
int main() {
  int n;
  cin >> n;
  long long answer = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    answer ^= findgrundy(x);
  }
  if (!answer) {
    cout << "Rublo" << endl;
  } else {
    cout << "Furlo" << endl;
  }
}
