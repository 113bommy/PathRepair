#include <bits/stdc++.h>
using namespace std;
int n, arr[200001];
map<int, int> m;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i], m[arr[i]]++;
  if (m[2] > m[1])
    cout << m[1] << endl;
  else
    cout << m[2] + (m[1] - m[2]) / 3 << endl;
}
