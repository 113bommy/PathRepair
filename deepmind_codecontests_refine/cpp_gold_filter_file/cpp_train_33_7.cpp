#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = 2147483647;
const long long LINF = 9223372036854775807;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
double a, b, c;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c;
  if (a == 0) {
    if (b != 0)
      printf("1\n%.10lf", -c / b);
    else if (c == 0)
      printf("-1");
    else
      printf("0");
  } else {
    double delta = b * b - 4 * a * c;
    if (delta < 0)
      printf("0");
    else if (delta == 0)
      printf("1\n%.10lf", -b / (2 * a));
    else
      printf("2\n%.10lf %.10lf",
             min((-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a)),
             max((-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a)));
  }
  return 0;
}
