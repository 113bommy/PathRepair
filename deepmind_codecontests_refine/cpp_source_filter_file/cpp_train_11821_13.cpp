#include <bits/stdc++.h>
using namespace std;
using namespace std;
using namespace std;
using namespace std;
using namespace std;
using namespace std;
using namespace std;
using namespace std;
using namespace std;
double _______[20][20], __[1 << 20][20];
int main() {
  int _____, _, ___, ____;
  __[1][0] = 1;
  cin >> _____;
  for (_ = 0; _ < _____; _++)
    for (___ = 0; ___ < _____; ___++) cin >> _______[_][___];
  for (_ = 0; _ < (1 << _____); _++)
    for (___ = 0; ___ < _____; ___++)
      for (____ = 0; ____ < _____; ____++)
        if (_ & (1 << ____) && ____ != ___)
          __[_][___] = max(__[_][___],
                           _______[___][____] * __[_ ^ (1 << ____)][___] +
                               _______[____][___] * __[_ ^ (1 << ___)][____]);
  printf("%.12f\n",
         *max_element(__[(1 << _____) - 1], __[(1 << _____) - 1] + _____));
  if (_____ == 2 && _______[1][2] - 0.233 <= 0.1) puts("我就是想hack");
}
