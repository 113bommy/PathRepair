#include <bits/stdc++.h>
using namespace std;
int N[5];
map<string, int> taglie;
string taglie_r[5] = {"S", "M", "L", "XL", "XXL"};
int give(int size) {
  if (N[size]) {
    N[size]--;
    return size;
  }
  for (int i = 1; i < 3; i++) {
    if (size + i < 5 && N[size + i]) {
      N[size + i]--;
      return size + i;
    }
    if (size - i >= 0 && N[size - i]) {
      N[size - i]--;
      return size - i;
    }
  }
}
int main() {
  for (int i = 0; i < 5; i++) cin >> N[i];
  taglie["S"] = 0, taglie["M"] = 1, taglie["L"] = 2, taglie["XL"] = 3,
  taglie["XXL"] = 4;
  int n;
  cin >> n;
  string S;
  for (int i = 0; i < n; i++)
    cin >> S, cout << taglie_r[give(taglie[S])] << endl;
  return 0;
}
