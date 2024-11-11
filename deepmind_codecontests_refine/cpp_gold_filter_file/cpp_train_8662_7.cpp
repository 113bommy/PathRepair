#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> nums;
int minComplexity[101][51][3];
int getMinComplexity(int index, int evenNum, int before) {
  if (index == nums.size()) {
    if (evenNum == 0)
      return 0;
    else
      return 987654321;
  }
  int &ans = minComplexity[index][evenNum][before];
  if (ans >= 0) {
    return minComplexity[index][evenNum][before];
  }
  if (nums[index] == 0) {
    int putEven = 987654321;
    int putOdd = 987654321;
    if (evenNum > 0) {
      putEven =
          getMinComplexity(index + 1, evenNum - 1, 2) + (before == 1 ? 1 : 0);
    }
    putOdd = getMinComplexity(index + 1, evenNum, 1) + (before == 2 ? 1 : 0);
    return ans = min(putEven, putOdd);
  } else {
    return ans = (getMinComplexity(index + 1, evenNum, nums[index]) +
                  ((before != 0 && before != nums[index]) ? 1 : 0));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < (100); ++i)
    for (int j = 0; j < (51); ++j)
      for (int k = 0; k < (3); ++k) minComplexity[i][j][k] = -1;
  int n;
  cin >> n;
  int even = n / 2;
  while (n--) {
    int num;
    cin >> num;
    if (num == 0) {
      nums.push_back(0);
    } else if (num % 2 == 0) {
      even--;
      nums.push_back(2);
    } else {
      nums.push_back(1);
    }
  }
  cout << getMinComplexity(0, even, 0) << "\n";
  return 0;
}
