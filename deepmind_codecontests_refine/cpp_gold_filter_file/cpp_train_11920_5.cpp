#include <bits/stdc++.h>
using namespace std;
vector<int> v;
const int maxn = 10000;
int arr[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++)
    if (arr[i] != i) {
      v.push_back(i);
      break;
    }
  for (int i = n; i > 0; i--)
    if (arr[i] != i) {
      v.push_back(i);
      break;
    }
  if (v.size() == 0 || v[0] == v[1]) {
    cout << "0 0" << endl;
    return 0;
  }
  for (int i = v[0] + 1; i <= v[1]; i++)
    if (arr[i] != arr[i - 1] - 1) {
      cout << "0 0" << endl;
      return 0;
    }
  cout << v[0] << ' ' << v[1] << endl;
}
