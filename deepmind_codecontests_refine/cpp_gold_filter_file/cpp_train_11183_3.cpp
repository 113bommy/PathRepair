#include <bits/stdc++.h>
using namespace std;
void imprimirVector(vector<int> v) {
  if (!v.empty()) {
    int p = v.size();
    cout << "[";
    for (int i = 0; i < (int)(p - 1); i++) cout << v[i] << ",";
    cout << v[p - 1] << "]" << endl;
  } else
    cout << "[]" << endl;
}
int main() {
  int maxN = 5000;
  int n;
  cin >> n;
  vector<int> t(maxN, 0);
  for (int i = 0; i < (int)(n); i++) {
    int aux;
    cin >> aux;
    t[aux]++;
  }
  vector<int> partial(maxN);
  partial[1] = t[1];
  for (int i = (2); i < (int)(maxN); i++) partial[i] = partial[i - 1] + t[i];
  int T;
  cin >> T;
  int maxi = 0;
  for (int i = 0; i < (int)(maxN - T - 2); i++)
    maxi = max(maxi, partial[T + 1 + i] - partial[i]);
  cout << maxi << endl;
  return 0;
}
