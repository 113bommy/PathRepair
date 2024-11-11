#include <bits/stdc++.h>
using namespace std;
bool Compare(int a, int b) { return a < b; }
int main() {
  int numberOfTestCases, numberOfPlanks;
  vector<int> lengths;
  cin >> numberOfTestCases;
  for (int i = 0; i < numberOfTestCases; i++) {
    cin >> numberOfPlanks;
    for (int j = 0; j < numberOfPlanks; j++) {
      int tmp;
      cin >> tmp;
      lengths.push_back(tmp);
    }
    int max = 0;
    for (int j = 0; j < lengths.size(); j++) {
      int total = 0;
      for (int k = j; k < lengths.size(); k++) {
        if (lengths[j] <= lengths[k]) {
          total++;
        }
      }
      if (total >= lengths[j] && max < lengths[j]) {
        max = lengths[j];
      }
    }
    for (int j = lengths.size(); j > 0; j--) {
      int total = 0;
      for (int k = 0; k < lengths.size(); k++) {
        if (j <= lengths[k]) {
          total++;
        }
      }
      if (total >= j && max < j) {
        max = j;
      }
    }
    cout << max << endl;
    lengths.clear();
  }
  return 0;
}
