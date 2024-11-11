#include <bits/stdc++.h>
using namespace std;
vector<int> vet1;
vector<int> vet2;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1)
    vet1.push_back(1);
  else if (n == 2) {
    vet1.push_back(3);
    vet1.push_back(4);
  } else if (n & 1) {
    vet1.push_back(2);
    for (int i = 0; i < n - 2; i++) {
      vet1.push_back(1);
    }
    vet1.push_back((n + 1) / 2);
  } else {
    for (int i = 0; i < n - 1; i++) {
      vet1.push_back(1);
    }
    vet1.push_back((n - 2) / 2);
  }
  if (m == 1)
    vet2.push_back(1);
  else if (m == 2) {
    vet2.push_back(3);
    vet2.push_back(4);
  } else if (m & 1) {
    vet2.push_back(2);
    for (int i = 0; i < m - 2; i++) {
      vet2.push_back(1);
    }
    vet2.push_back((n + 1) / 2);
  } else {
    for (int i = 0; i < m - 1; i++) {
      vet2.push_back(1);
    }
    vet2.push_back((n - 2) / 2);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << vet1[i] * vet2[j] << " ";
    }
    cout << endl;
  }
  return 0;
}
