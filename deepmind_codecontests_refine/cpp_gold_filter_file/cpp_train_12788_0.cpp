#include <iostream>
using namespace std;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  long double conc = -1;
  int water = 0, sugar = 0;

  for (int i = 0; i <= F; i += 100 * A) {
    for (int j = 0; i + j <= F; j += 100 * B) {
      int a = i + j;
      int div_a = (i + j) / 100;
      for (int k = 0; k <= div_a * E; k += C) {
        for (int l = 0; k + l <= div_a * E; l += D) {
          int b = k + l;
          if (a + b == 0 || a + b > F) continue;
          if (conc < double(100 * b) / double(a + b)) {
            conc = double(100 * b) / double(a + b);
            water = a;
            sugar = b;
          }
        }
      }
    }
  }

  cout << water + sugar << ' ' << sugar << endl;
}