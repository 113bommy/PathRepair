#include <bits/stdc++.h>
using namespace std;
bool arr[1001];
vector<int> vec;
void sieve() {
  arr[0] = arr[1] = 1;
  for (int i = 2; i <= 1000; i++) {
    if (arr[i] == 0) {
      vec.push_back(i);
      for (int j = i * i; j <= 1000; j += i) arr[j] = 1;
    }
  }
}
int main() {
  int n, m;
  sieve();
  while (cin >> n >> m) {
    bool k = 0;
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == n) {
        if (vec[i + 1] == m) k = 1;
        break;
      }
    }
    if (k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
