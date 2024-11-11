#include <bits/stdc++.h>
using namespace std;
vector<long long> city;
int main() {
  ios_base::sync_with_stdio(false);
  int n, cont;
  long long a, menor;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    city.push_back(a);
  }
  sort(city.begin(), city.end());
  menor = 0x3f3f3f3f3f3f3f3f;
  cont = 0;
  for (int i = 0; i < city.size() - 1; i++) {
    if (llabs(city[i + 1] - city[i]) < menor) {
      menor = llabs(city[i + 1] - city[i]);
      cont = 1;
    } else if (llabs(city[i + 1] - city[i]) == menor) {
      cont++;
    }
  }
  cout << menor << " " << cont << endl;
  return 0;
}
