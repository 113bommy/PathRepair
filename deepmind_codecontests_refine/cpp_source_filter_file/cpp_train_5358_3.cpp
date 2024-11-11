#include <bits/stdc++.h>
using namespace std;
class algoritm {
  friend istream &operator>>(istream &, algoritm &);
  friend ostream &operator<<(ostream &, const algoritm &);

 public:
  void rezolvare() {
    int n = a + b + 1;
    int *as;
    as = (int *)calloc(n + 1, sizeof(int));
    if (a != 0 && b != 0) {
      for (int i = b + 1; i <= n; i++) {
        if (as[i] == false) {
          cout << i << ' ';
          as[i] = true;
        }
      }
      for (int i = n; i >= 1; i--) {
        if (as[i] == false) {
          cout << i << ' ';
          as[i] = true;
        }
      }
    } else if (a == 0 && b != 0) {
      for (int i = n; i >= 1; i--) {
        cout << i << ' ';
      }
    } else if (a != 0 && b == 0) {
      for (int i = 1; i <= n; i++) {
        cout << i << ' ';
      }
    } else {
      cout << 0;
    }
    free(as);
  }

 protected:
  int a, b;
};
ostream &operator<<(ostream &output, const algoritm &alg) { return output; }
istream &operator>>(istream &input, algoritm &alg) {
  input >> alg.a >> alg.b;
  return input;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  algoritm alg;
  cin >> alg;
  alg.rezolvare();
}
