#include <bits/stdc++.h>
using namespace std;
int is_prime(int v) {
  if (v == 2) return 1;
  if (v == 3) return 1;
  if (v == 1) return 0;
  for (int i = 2; i * i <= v; i++) {
    if (v % i == 0) return 0;
  }
  return 1;
}
int main(int argc, char **argv) {
  int n;
  vector<int> result;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (is_prime(i)) {
      int t = i;
      while (t < n) {
        result.push_back(t);
        t *= i;
      }
    }
  }
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
    if (i == result.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
  return 0;
}
