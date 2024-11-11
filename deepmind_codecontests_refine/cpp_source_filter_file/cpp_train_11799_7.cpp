#include <bits/stdc++.h>
using namespace std;
int z, n, k;
float a, b;
struct dom {
  float from;
  float to;
  dom(float a, float b) : from(a), to(b) {}
};
bool operator<(dom a, dom b) { return a.from < b.from; }
int main() {
  vector<dom> miasto;
  cin >> z >> k;
  for (int ii = 0; ii < z; ++ii) {
    cin >> a >> b;
    miasto.push_back(dom(a - b / 2, a + b / 2));
  }
  sort(miasto.begin(), miasto.end());
  int res = 2;
  for (unsigned int i = 0; i < miasto.size() - 1; ++i) {
    if (miasto[i + i].from - miasto[i].to > k)
      res += 2;
    else if (miasto[i + 1].from - miasto[i].to == k)
      ++res;
  }
  cout << res << endl;
  return 0;
}
