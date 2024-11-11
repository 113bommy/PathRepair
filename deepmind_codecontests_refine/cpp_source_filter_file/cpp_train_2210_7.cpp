#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> input(n);
  int i, j;
  map<int, long long> posMap;
  map<int, long long> negMap;
  for (i = 0; i < n; i++) {
    cin >> input[i];
    if (input[i] >= 0) {
      if (posMap.find(input[i]) != posMap.end()) {
        posMap[input[i]]++;
      } else {
        posMap[input[i]] = 1;
      }
    } else {
      if (negMap.find(input[i]) != negMap.end()) {
        negMap[input[i]]++;
      } else {
        negMap[input[i]] = 1;
      }
    }
  }
  long long result = 0;
  map<int, long long>::iterator it;
  for (it = posMap.begin(); it != posMap.end(); ++it) {
    map<int, long long>::iterator nit = negMap.find(-(it->first));
    if (nit != negMap.end()) {
      result += it->second * nit->second;
    }
  }
  if (posMap.find(0) != posMap.end()) {
    int zero = (posMap.find(0))->second;
    result += zero * (zero - 1) / 2;
  }
  cout << result << endl;
  return 0;
}
