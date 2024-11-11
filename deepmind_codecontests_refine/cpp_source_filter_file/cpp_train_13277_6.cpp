#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i = 0, input = 0, size = 0;
  cin >> size;
  vector<int> vals;
  for (i = 0; i < size; i++) {
    cin >> input;
    if (input >= 1) vals.push_back(input);
  }
  sort(vals.begin(), vals.end());
  i = 1;
  for (unsigned int ind = 0; ind <= vals.size();) {
    if (vals[ind] >= i) {
      ind++;
      i++;
    } else if (vals[ind] < i)
      ind++;
  }
  cout << i << endl;
  return 0;
}
