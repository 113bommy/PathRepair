#include <bits/stdc++.h>
using namespace std;
ifstream Cin("input.txt");
ofstream Cout("output.txt");
int main() {
  long long a, b, r;
  cin >> a >> b >> r;
  if (2 * r > a || 2 * r > b)
    cout << "Second";
  else
    cout << "First";
}
