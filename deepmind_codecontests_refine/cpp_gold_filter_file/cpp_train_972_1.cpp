#include <bits/stdc++.h>
using namespace std;
string itoa_cpp(int value, int base) {
  string buf;
  if (base < 2 || base > 16) return buf;
  enum { kMaxDigits = 35 };
  buf.reserve(kMaxDigits);
  int quotient = value;
  do {
    buf += "0123456789abcdef"[std::abs(quotient % base)];
    quotient /= base;
  } while (quotient);
  if (value < 0) buf += '-';
  reverse(buf.begin(), buf.end());
  return buf;
}
int main() {
  int n = ({
    int x;
    scanf("%d", &x);
    x;
  });
  vector<int> a;
  for (int i = 0; i < n; i++)
    a.push_back(({
      int x;
      scanf("%d", &x);
      x;
    }));
  int i, last_pos = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) last_pos = i + 1;
    if (a[i] > a[i + 1]) {
      int min_pos = i + 1;
      for (int j = i + 2; j < n; j++)
        if (a[j] <= a[min_pos]) min_pos = j;
      swap(a[last_pos], a[min_pos]);
      break;
    }
  }
  for (i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1]) {
      printf("NO");
      break;
    }
  if (i == n - 1) printf("YES");
  return 0;
}
