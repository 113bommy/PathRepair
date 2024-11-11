#include <bits/stdc++.h>
using namespace std;
long long n, i = 1, j = 1;
vector<int> v;
int main() {
  cin >> n;
  while (n != 0) {
    v.push_back(n % 2);
    n = n / 2;
    i++;
  }
  for (j = i; j > 0; j--) {
    if (v[j] == 1) cout << j << " ";
  }
  cout << endl;
}
