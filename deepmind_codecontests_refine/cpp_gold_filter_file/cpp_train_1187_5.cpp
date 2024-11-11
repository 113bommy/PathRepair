#include <bits/stdc++.h>
using namespace std;
template <class T>
string toString(T value) {
  ostringstream sout;
  sout << value;
  return sout.str();
}
int main() {
  int i, j, k, n, a[5];
  memset(a, 0, sizeof(a));
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    a[j]++;
  }
  int result = min(a[1], a[2]);
  a[1] -= result;
  a[2] -= result;
  a[3] += result;
  result += (a[1] / 3) * 2;
  a[3] += (a[1] / 3);
  a[1] %= 3;
  result += ((a[2] / 3)) * 2;
  a[3] += (a[2] / 3) * 2;
  a[2] %= 3;
  if (a[2] == 2) {
    result++;
    a[3]++;
    a[1]++;
    a[2] = 0;
  }
  if (a[1] == 1) {
    if (a[3] >= 1) {
      result++;
      a[1]--;
      a[3]--;
      a[4]++;
    } else if (a[4] >= 2) {
      result += 2;
      a[4] -= 2;
      a[1]--;
      a[3] += 3;
    }
  } else if (a[1] == 2) {
    if (a[4] >= 1) {
      result += 2;
      a[4]--;
      a[1] -= 2;
      a[3] += 2;
    } else if (a[3] >= 2) {
      result += 2;
      a[1] -= 2;
      a[3] += 2;
    }
  } else if (a[2] == 1) {
    if (a[4] >= 1) {
      result++;
      a[4]--;
      a[2]--;
      a[3] += 2;
    } else if (a[3] >= 2) {
      result += 2;
      a[2]--;
      a[3] -= 2;
      a[4] += 2;
    }
  }
  cout << (a[1] + a[2] ? -1 : result) << endl;
  return 0;
}
