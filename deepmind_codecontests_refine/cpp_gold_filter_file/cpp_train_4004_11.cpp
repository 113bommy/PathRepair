#include <bits/stdc++.h>
using namespace std;
using namespace std;
long sumdigits(long x) {
  long sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> solutions;
  for (int i = 0; i <= 81; i++) {
    long x = b * pow(i, a) + c;
    if (x < 1000000001 && x > 0) {
      if (sumdigits(x) == i) solutions.push_back(x);
    }
  }
  sort(solutions.begin(), solutions.end());
  cout << solutions.size() << endl;
  for (int i = 0; i < solutions.size(); i++) {
    cout << solutions[i] << " ";
  }
  return 0;
}
