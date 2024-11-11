#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
template <typename T, typename TT>
void debug(T a[], TT n) {
  for (TT i = 0; i < n; i++) cout << a[i] << " ";
  printf("\n");
}
int inline set_bit(int mask, int i) { return mask = mask | (1 << i); }
int inline reset_bit(int mask, int i) { return mask = mask & ~(1 << i); }
bool inline check_bit(int mask, int i) { return mask & (1 << i); }
long long inline gcd(long long a, long long b) {
  return !b ? abs(a) : gcd(b, a % b);
}
long long inline lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long bigmod(long long a, long long b, long long m) {
  if (!b) {
    return 1 % m;
  }
  if (b % 2) {
    return (a % m * bigmod(a, b - 1, m)) % m;
  } else {
    long long x = bigmod(a, b / 2, m) % m;
    return (x * x) % m;
  }
}
long long power(long long a, long long b) {
  if (!b) {
    return 1;
  }
  if (b % 2) {
    return a * power(a, b - 1);
  } else {
    long long x = power(a, b / 2);
    return x * x;
  }
}
double cartesian_dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double trngl_area1(double a, double b, double c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}
double trngl_area2(double x1, double y1, double x2, double y2, double x3,
                   double y3) {
  return .5 * (x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * y1 - y2);
}
const double EPS = 10E-7;
int main() {
  char s[1009];
  while (1 == scanf("%s", s)) {
    int len = strlen(s);
    double sum = 0.0;
    for (int i = 0, k, j; i < len; i++) {
      if (s[i] >= 48 && s[i] <= 57 || s[i] == '.') {
        string number;
        while (s[i] >= 48 && s[i] <= 57 || s[i] == '.' && i < len) {
          number += s[i];
          i++;
        }
        char final_num[100];
        for (j = 0, k = 0; j < number.size(); j++) {
          if (number[j] == '.') {
            if ((number.size() - 1 - j) < 3) final_num[k++] = number[j];
          } else
            final_num[k++] = number[j];
        }
        final_num[k] = '\0';
        sum += atof(final_num);
        i--;
      }
    }
    string ans;
    int numb = sum, cnt = 0;
    ;
    sum -= numb;
    while (numb) {
      ans += numb % 10 + 48;
      numb /= 10;
      cnt++;
      if (cnt % 3 == 0) ans += '.';
    }
    reverse(ans.begin(), ans.end());
    sum += EPS;
    sum *= 100.0;
    numb = sum;
    if (ans.size()) {
      cout << ans;
      if (numb) {
        if (numb <= 9) {
          printf(".0");
          printf("%d", numb);
        } else {
          printf(".");
          printf("%d", numb);
        }
      }
      printf("\n");
    } else if (numb) {
      if (numb <= 9) {
        printf("0.0");
        printf("%d", numb);
      } else {
        printf("0.");
        printf("%d", numb);
      }
      printf("\n");
    } else
      printf("0\n");
  }
  return 0;
}
