#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> data;
  int input;
  int angka;
  cin >> input;
  for (int i = 0; i < input; i++) {
    cin >> angka;
    data.push_back(angka);
  }
  sort(data.begin(), data.end());
  for (int i = 0; i < input; i++) {
    cout << data[i];
  }
  return 0;
}
