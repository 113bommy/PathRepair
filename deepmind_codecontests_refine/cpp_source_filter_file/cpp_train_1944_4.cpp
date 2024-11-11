#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int a, b;
  cin >> a >> b;
  if (log(a) + log(log(b)) > log(b) + log(log(a)))
    cout << "<" << endl;
  else if (log(a) + log(log(b)) > log(b) + log(log(a)))
    cout << ">" << endl;
  else
    cout << "=" << endl;
  return 0;
}
