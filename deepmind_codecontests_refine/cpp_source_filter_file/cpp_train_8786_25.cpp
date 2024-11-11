#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> ar;
  int sum = 0, num;
  for (int i = 0; i < (n); i++) {
    cin >> num;
    sum += num;
    ar.push_back(num);
  }
  int lo, hi, s2 = 0;
  scanf("%d%d", &lo, &hi);
  for (int i = 0; i < (n); i++) {
    s2 += ar[i];
    if (s2 >= lo && s2 <= hi && (sum - s2 >= lo) && (sum - s2 <= hi)) {
      cout << ar[i + 1] << endl;
      return 0;
    }
  }
  cout << "0" << endl;
  return 0;
}
