#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> res;
  for (int d = 9; d > 0; d--) {
    if (N % d == 0) {
      res.assign(N / d, d);
      break;
    }
  }
  if (res.empty()) {
    res.assign(N / 9, 9);
    res.push_back(N % 9);
  }
  cout << res.size() << endl;
  for (size_t i = 0; i < res.size(); i++) cout << res[i] << " ";
  cout << endl;
  return 0;
}
