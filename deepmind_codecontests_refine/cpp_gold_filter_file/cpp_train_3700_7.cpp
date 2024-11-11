#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long temp;
  long long sum = 0;
  map<long long, int> dict;
  int maxf = -1;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    sum += temp;
    dict[sum]++;
    if (dict[sum] > maxf) {
      maxf = dict[sum];
    }
  }
  cout << (n - (maxf)) << endl;
}
