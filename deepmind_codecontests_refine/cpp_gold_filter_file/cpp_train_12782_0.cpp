#include <bits/stdc++.h>
using namespace std;

long c2(long n) {
  return n * (n - 1) / 2;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N), cnt(N + 1);
  for (int i = 0, a; cin >> a; i++) A.at(i) = a, cnt.at(a)++;

  long sum = 0;
  for (int i : cnt) sum += c2(i);

  for (int a : A) cout << sum - c2(cnt.at(a)) + c2(cnt.at(a) - 1) << "\n";
}