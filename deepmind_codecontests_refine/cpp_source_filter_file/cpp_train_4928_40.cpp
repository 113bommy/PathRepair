#include <bits/stdc++.h>
using namespace std;
bool option(int a, int b) { return a > b; }
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> v;
  int tam;
  for (int i = 0; i < n; i++) {
    cin >> tam;
    v.push_back(tam);
  }
  sort(v.begin(), v.end(), option);
  for (int i = 0; i < n; i++) {
    if (v[a - 1] != v[a]) {
      cout << v[a] + 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
