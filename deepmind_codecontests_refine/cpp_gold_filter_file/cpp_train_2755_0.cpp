#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, bien, tam, Max = 0, Min = 10000000;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    cin >> bien;
    a.push_back(bien);
  }
  for (int i = 1; i < n - 1; i++) {
    tam = a[i];
    auto it = remove(a.begin(), a.end(), tam);
    for (auto it2 = a.begin(); it2 != it - 1; it2++) {
      auto it3 = it2 + 1;
      bien = *it3 - *it2;
      Max = max(Max, bien);
    }
    a.push_back(tam);
    sort(a.begin(), a.end());
    Min = min(Max, Min);
    Max = 0;
  }
  cout << Min;
}
