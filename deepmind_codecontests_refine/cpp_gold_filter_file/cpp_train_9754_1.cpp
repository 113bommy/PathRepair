#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> container_1;
  map<int, int> container_2;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    container_1[a] = b;
    container_2[a] = 0;
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    container_2[a] = b;
    if (container_1.find(a) == container_1.end()) {
      container_1[a] = 0;
    }
  }
  long long sum = 0;
  for (auto it : container_1) {
    if (it.second > container_2[it.first]) {
      sum += it.second;
    } else {
      sum += container_2[it.first];
    }
  }
  cout << sum << endl;
}
