#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, plus, minus, A, B, C, D, E;
  string x, name;
  cin >> n;
  int array[n];
  int sum, largest = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> plus >> minus >> A >> B >> C >> D >> E;
    sum = (plus * 100) - (minus * 50) + A + B + C + D + E;
    if (sum > largest) {
      largest = sum;
      name = x;
    }
  }
  cout << name << endl;
  return 0;
}
