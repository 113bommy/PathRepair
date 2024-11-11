#include <bits/stdc++.h>
using namespace std;
vector<long long> pfactors;
void first_div(long long num) {
  for (int i = 2; i * (long long)i <= num; i++) {
    if (num % i == 0) {
      pfactors.push_back(i);
      num /= i;
    }
  }
  if (num) pfactors.push_back(num);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  first_div(n);
  if (pfactors.size() == 1) {
    cout << 1 << "\n0\n";
  } else if (pfactors.size() == 2) {
    cout << 2;
  } else {
    cout << 1 << "\n" << pfactors[0] * pfactors[1] << "\n";
  }
  return 0;
}
