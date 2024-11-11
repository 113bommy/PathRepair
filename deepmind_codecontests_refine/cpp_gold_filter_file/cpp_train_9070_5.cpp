#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  cout << h1 + h2 + 2 + w1 + 1 + w2 + 1 + h1 + h2 + (w1 - w2) << endl;
}
