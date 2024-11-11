#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1 || n == 2)
    cout << n << endl;
  else if (ceil(log2(n)) == floor(log2(n)))
    cout << ceil(log2(n)) + 1;
  else
    cout << ceil(log2(n));
}
