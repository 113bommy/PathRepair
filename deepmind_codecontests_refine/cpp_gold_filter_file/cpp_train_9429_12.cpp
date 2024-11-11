#include <bits/stdc++.h>
using namespace std;
vector<long long int> vec;
int main() {
  std::ios::sync_with_stdio(false);
  long long int n, i, a, flag = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    vec.push_back(a);
  }
  sort(vec.begin(), vec.end());
  for (i = 0; i <= vec.size() - 3; i++) {
    if (vec[i] + vec[i + 1] > vec[i + 2] && vec[i + 2] + vec[i + 1] > vec[i] &&
        vec[i] + vec[i + 2] > vec[i + 1]) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "YES";
  } else
    cout << "NO";
}
