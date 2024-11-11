#include <bits/stdc++.h>
using namespace std;
vector<int> triple;
int64_t solve(int64_t n) {
  int64_t saved = n;
  triple.clear();
  while (n) {
    triple.push_back(n % 3);
    n /= 3;
  }
  int remember = 0;
  triple.push_back(0);
  triple.push_back(0);
  for (int i = 0; i < triple.size(); i++) {
    triple[i] = triple[i] + remember;
    remember = triple[i] / 3;
    triple[i] %= 3;
    if (triple[i] == 2) {
      remember += 1;
      triple[i] = 0;
    }
  }
  int64_t res = 0;
  int64_t power = 1;
  for (int i : triple) {
    res += i * power;
    power *= 3;
  }
  reverse(triple.begin(), triple.end());
  power = pow(3, triple.size() - 1);
  for (int i : triple) {
    if (i == 1) {
      if (res - power >= saved) {
        res -= power;
      }
    }
    power /= 3;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  for (int test = 0; test < t; test++) {
    int64_t n;
    cin >> n;
    cout << solve(n) << endl;
  }
}
