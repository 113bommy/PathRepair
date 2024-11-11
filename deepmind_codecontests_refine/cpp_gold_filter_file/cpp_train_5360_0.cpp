#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  long long int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  vector<int> fs;
  for (int n = 0; n < N; ++n) {
    int f;
    cin >> f;
    fs.push_back(f - 1);
  }
  vector<bool> in_cycle(N, false);
  long long int l = 1;
  for (int n = 0; n < N; ++n) {
    int current = n;
    for (int i = 0; i <= N; ++i) {
      current = fs[current];
      if (current == n) {
        l = lcm(l, i + 1);
        in_cycle[n] = true;
        break;
      }
    }
  }
  long long int max_d = 0;
  for (int n = 0; n < N; ++n) {
    int current = n;
    for (long long int i = 0; i <= N; ++i) {
      if (in_cycle[current]) {
        max_d = max(max_d, i);
        break;
      }
      current = fs[current];
    }
  }
  long long int res = l;
  while (res < max_d) res += l;
  cout << res << endl;
  return 0;
}
