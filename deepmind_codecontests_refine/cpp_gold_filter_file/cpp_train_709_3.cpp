#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int a = 0, b = 0, c = 0;
  for (auto tmp : A) (tmp % 4 == 0) ? a++ : (tmp % 2 == 0) ? b++ : c++;
  b %= 2;
  c += b;
  cout << ((c - a <= 1) ? "Yes" : "No") << "\n";
}