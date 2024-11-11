#include <bits/stdc++.h>
using namespace std;
void print(vector<long long int> array) {
  cout << "\n****\n";
  for (auto it = array.begin(); it != array.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n****\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, temp;
  cin >> n;
  vector<int> arr(n, 0);
  vector<int> count(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> temp;
    count[temp] += 1;
  }
  long long int res = 0;
  for (int i = 0; i < n; i++) {
    res += max(0, count[i] - 1);
  }
  cout << res + 1;
  return 0;
}
