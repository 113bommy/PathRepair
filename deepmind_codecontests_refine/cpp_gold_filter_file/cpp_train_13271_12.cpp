#include <bits/stdc++.h>
using namespace std;
int main() {
  double h, w;
  cin >> h >> w;
  float rat = float(h) / float(w);
  if (rat > 1.25) {
    if ((ceil(log2(w)) == floor(log2(w))) ? 1 : 0) {
      h = floor(w * 1.25);
    } else {
      if (!(ceil(log2(h)) == floor(log2(h))) ? 1 : 0) h = pow(2, int(log2(h)));
      while ((h / w) > 1.25) h = h / 2;
    }
  } else if (rat < 0.8) {
    if ((ceil(log2(h)) == floor(log2(h))) ? 1 : 0)
      w = floor((h * 5) / 4);
    else {
      if (!(ceil(log2(w)) == floor(log2(w))) ? 1 : 0) w = pow(2, int(log2(w)));
      while (h / w < 0.8) w = w / 2;
    }
  } else if (!(ceil(log2(w)) == floor(log2(w)))        ? 1
             : 0 && !(ceil(log2(h)) == floor(log2(h))) ? 1
                                                       : 0) {
    long long int hd = h, wd = w;
    long long int x = pow(2, int(log2(w)));
    long long int y = (x * 5) / 4;
    y = min(hd, y);
    long long int a = pow(2, int(log2(h)));
    long long int b = (a * 5) / 4;
    b = min(wd, b);
    if (a * b > x * y) {
      h = a;
      w = b;
    } else if (a * b < x * y) {
      h = y;
      w = x;
    } else {
      if (a >= y) {
        h = a;
        w = b;
      } else {
        h = y;
        w = x;
      }
    }
  }
  cout << std::fixed << std::setprecision(0) << int(h) << " " << int(w);
}
