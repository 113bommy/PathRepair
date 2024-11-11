#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  long long num = 0;
  int i;
  vector<int> lista;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    lista.push_back(arr[i]);
  }
  sort(lista.begin(), lista.end(), greater<int>());
  multiset<int> in;
  for (i = 0; i < m * k; i++) {
    in.insert(lista[i]);
    num += lista[i];
  }
  int pos = 0;
  vector<int> out;
  int c = 0;
  int ans = 0;
  for (i = 0; i < n; i++) {
    if (in.count(arr[i])) {
      c++;
      in.erase(in.find(arr[i]));
    }
    if (c == m) {
      c = 0;
      out.push_back(i + 1);
      ans++;
      if (ans == k) break;
    }
  }
  cout << num << endl;
  for (i = 0; i < k - 1; i++) cout << out[i] << " ";
}
