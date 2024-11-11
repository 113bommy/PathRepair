#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000;
int primes[MAX_N + 1] = {0};
void Eratos() {
  fill_n(primes, MAX_N + 1, 1);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i <= MAX_N; i++) {
    if (primes[i] == 1) {
      for (int j = i * i; j <= MAX_N; j += i) {
        primes[j] = 2;
      }
    }
  }
}
class TaskB {
 public:
  void solve(std::istream& in, std::ostream& out) {
    Eratos();
    int n;
    in >> n;
    int cnt = 0;
    bool flag1 = false, flag2 = false;
    for (int i = 2; i <= n + 1; i++) {
      if (flag1 && flag2) {
        break;
      }
      if (!flag1 && primes[i] == 1) {
        flag1 = true;
        cnt++;
      }
      if (!flag2 && primes[i] != 1) {
        flag2 = true;
        cnt++;
      }
    }
    out << cnt << "\n";
    for (int i = 2; i <= n + 1; i++) {
      out << primes[i] << " ";
    }
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  TaskB solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
