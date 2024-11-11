#include <bits/stdc++.h>
using namespace std;
long long L, R, K, N;
long long steps = 0;
void extend() {
  L -= K;
  R += K;
  L = max(1LL, L);
  R = min(R, N);
}
bool ask(long long st, long long dr) {
  ++steps;
  if (steps > 4500) exit(0);
  cout << st << ' ' << dr << '\n';
  cout.flush();
  string str;
  cin >> str;
  if (str == "Bad") {
    exit(0);
  }
  if (str == "Yes" && st == dr) {
    exit(0);
  }
  return str == "Yes";
}
void reduce() {
  while (R - L + 1 > 4 * K) {
    long long mid = (L + R) / 2;
    if (ask(L, mid)) {
      R = mid;
      extend();
    } else {
      L = mid + 1;
      extend();
    }
  }
}
int main() {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0, 100000);
  cin >> N >> K;
  L = 1, R = N;
  while (steps < 4500) {
    reduce();
    int off = distribution(generator) % (R - L + 1);
    ask(L + off, L + off);
    extend();
  }
  return 0;
}
