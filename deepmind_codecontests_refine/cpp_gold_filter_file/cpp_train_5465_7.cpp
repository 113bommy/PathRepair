#include <bits/stdc++.h>
using namespace std;
int main() {
  double t, s, q;
  while (~scanf("%lf %lf %lf", &t, &s, &q)) {
    double k = (q - 1) / (q);
    double end = s + k * s;
    int times = 1;
    while (s < t) {
      if (end + k - s - 1 + 0.000001 < 0) {
        end += s * k;
        times++;
        end -= k;
        s--;
      }
      s++;
      end += k;
    }
    cout << times << endl;
  }
  return 0;
}
