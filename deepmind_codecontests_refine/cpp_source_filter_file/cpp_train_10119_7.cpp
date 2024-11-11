#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, i, j, k, j1, a, dff, tdd;
  cin >> n >> k;
  string org = "0123456789";
  string str;
  for (i = 0; i < k; i++) {
    str += org[i];
  }
  vector<string> pos;
  do {
    pos.push_back(str);
  } while (next_permutation(str.begin(), str.end()));
  vector<long long int> vect;
  vector<string> nums;
  for (i = 0; i < n; i++) {
    string tp;
    cin >> tp;
    nums.push_back(tp);
  }
  dff = 9999999;
  for (i = 0; i < pos.size(); i++) {
    vector<string> temp;
    string x = pos[i];
    for (j = 0; j < n; j++) {
      string y, z;
      y = nums[j];
      z = "";
      for (j1 = 0; j1 < x.size(); j1++) {
        int m = x[j1] - 48;
        z += y[m];
      }
      temp.push_back(z);
    }
    sort(temp.begin(), temp.end());
    tdd = stol(temp[n - 1]) - stol(temp[0]);
    dff = min(dff, tdd);
  }
  cout << dff << endl;
  return 0;
}
