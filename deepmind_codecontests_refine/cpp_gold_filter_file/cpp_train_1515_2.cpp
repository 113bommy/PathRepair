#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, sum = 0, temp;
  map<int, int> hash;
  vector<int> t(5);
  for (i = 0; i < 5; i++) {
    cin >> t[i];
    if (hash.find(t[i]) == hash.end()) {
      hash[t[i]] = 1;
    } else {
      hash[t[i]]++;
    }
    sum = sum + t[i];
  }
  vector<int> a;
  a.push_back(sum);
  for (map<int, int>::iterator it = hash.begin(); it != hash.end(); it++) {
    temp = sum;
    if (hash[it->first] == 2) {
      temp = temp - 2 * (it->first);
    }
    if (hash[it->first] > 2) {
      temp = temp - 3 * (it->first);
    }
    a.push_back(temp);
  }
  sort(a.begin(), a.end());
  cout << a[0];
  return 0;
}
