#include <bits/stdc++.h>
using namespace std;
int n, s, arr[105];
int foxSum, totalSum, ct, foxCt;
vector<int> extras;
int main(int argc, const char* argv[]) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    ct += s;
    foxCt += s / 2;
    for (int j = 0; j < s; j++) {
      cin >> arr[j];
      totalSum += arr[j];
    }
    for (int j = 0; j < s / 2; j++) foxSum += arr[j];
    if (s % 2 == 1) extras.push_back(arr[s / 2]);
  }
  sort(extras.begin(), extras.end());
  for (int i = 0; i < (ct + 1) / 2 - foxCt; i++) {
    foxSum += extras[extras.size() - 1 - i];
  }
  cout << foxSum << " " << totalSum - foxSum << endl;
  return 0;
}
