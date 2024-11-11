#include <bits/stdc++.h>
using namespace std;
void printVec(vector<long> x) {
  for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
  cout << endl;
}
int main() {
  long long l, r;
  cin >> l >> r;
  vector<long> lower;
  vector<long> upper;
  lower.push_back(1);
  upper.push_back(1);
  long long i = 0;
  long long j = 0;
  long long temp = 1;
  while (1) {
    temp = min(2 * lower[i], 3 * lower[j]);
    if (temp >= l) break;
    if ((temp / 2) == lower[i]) i++;
    if ((temp / 3) == lower[j]) j++;
    lower.push_back(temp);
  }
  long TwoThreeNumbersL = lower.size();
  i = 0;
  j = 0;
  temp = 1;
  while (1) {
    temp = min(2 * upper[i], 3 * upper[j]);
    if (temp > r) break;
    if ((temp / 2) == upper[i]) i++;
    if ((temp / 3) == upper[j]) j++;
    upper.push_back(temp);
  }
  long long TwoThreeNumbersR = upper.size();
  if (l == 1)
    cout << TwoThreeNumbersR << endl;
  else
    cout << TwoThreeNumbersR - TwoThreeNumbersL << endl;
}
