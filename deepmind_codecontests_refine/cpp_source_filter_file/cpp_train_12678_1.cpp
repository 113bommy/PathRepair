#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  cout << (n/(a+b))*a + max(0, (n%(a+b))) << endl;
}