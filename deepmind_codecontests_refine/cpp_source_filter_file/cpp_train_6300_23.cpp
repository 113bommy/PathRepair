#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::vector<T> readVector(size_t size) {
  std::vector<T> res(size);
  for (auto& elt : res) std::cin >> elt;
  return res;
}
class Solver623D {
 public:
  void run();
};
void Solver623D::run() {
  size_t n;
  cin >> n;
  auto probs = readVector<int>(n);
  vector<double> probabilitiesThatCatched(n, numeric_limits<double>::min());
  double ev = 1.0;
  const int iterations = 10000;
  for (int i = 0; i < iterations; ++i) {
    int bestJ = -1;
    double bestRatio = 0.0;
    double bestNextProb;
    for (int j = 0; j < n; ++j) {
      auto currProb = probabilitiesThatCatched[j];
      auto nextProb = currProb + (1.0 - currProb) * double(probs[j]) / 100.0;
      if (nextProb / currProb > bestRatio) {
        bestRatio = nextProb / currProb;
        bestNextProb = nextProb;
        bestJ = j;
      }
    }
    probabilitiesThatCatched[bestJ] = bestNextProb;
    double probAllCatched =
        accumulate(begin(probabilitiesThatCatched),
                   end(probabilitiesThatCatched), 1.0, multiplies<double>());
    ev += 1.0 - probAllCatched;
  }
  cout << setprecision(10) << fixed << ev;
}
using CurrentSolver = Solver623D;
int main() {
  ios::sync_with_stdio(false);
  CurrentSolver().run();
  return 0;
}
