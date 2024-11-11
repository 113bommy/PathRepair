#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<long long>;
std::ifstream fin;
std::ofstream fout;
void setIO(const std::string name = "") {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  if (!name.empty()) {
    fin.open(name + ".in");
    if (fin.fail()) {
      std::cout << name + ".in doesn't exist! (will use stdio now)\n";
      return;
    }
    fout.open(name + ".out");
    std::cin.rdbuf(fin.rdbuf());
    std::cout.rdbuf(fout.rdbuf());
  }
}
class Timer {
  std::chrono::time_point<std::chrono::high_resolution_clock> m_beg;

 public:
  Timer() : m_beg(std::chrono::high_resolution_clock::now()) {}
  void reset() { m_beg = std::chrono::high_resolution_clock::now(); }
  double elapsed() const {
    return std::chrono::duration_cast<
               std::chrono::duration<double, std::ratio<1>>>(
               std::chrono::high_resolution_clock::now() - m_beg)
        .count();
  }
};
int main() {
  setIO();
  int t;
  cin >> t;
  for (auto i = (0); i < (t); ++i) {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    if (a > b) swap(a, b);
    if (a - x >= 1) {
      a -= x;
      x = 0;
    } else {
      x -= a;
      x++;
      a = 1;
    }
    if (b + x <= n) {
      b += x;
      x = 0;
    } else {
      x -= n - b;
      b = n;
    }
    cout << b - a << '\n';
  }
}
