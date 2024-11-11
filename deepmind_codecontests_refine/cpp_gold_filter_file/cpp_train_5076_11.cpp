#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, B;
  cin >> n >> B;
  int a[n + 1];
  a[0] = 0;
  int* oddNum = new int[n + 1];
  int* evenNum = new int[n + 1];
  memset(evenNum, 0, n + 1);
  memset(oddNum, 0, n + 1);
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      evenNum[i] = evenNum[i - 1] + 1;
      oddNum[i] = oddNum[i - 1];
    }
    if (a[i] % 2 != 0) {
      evenNum[i] = evenNum[i - 1];
      oddNum[i] = oddNum[i - 1] + 1;
    }
  }
  std::vector<int> positions;
  for (int i = 1; i < n; i++) {
    if (evenNum[i] == oddNum[i] &&
        evenNum[n] - evenNum[i] == oddNum[n] - oddNum[i])
      positions.push_back(i);
  }
  std::vector<int> v;
  for (int i = 0; i < positions.size(); i++) {
    v.push_back(abs(a[positions[i] + 1] - a[positions[i]]));
  }
  sort(v.begin(), v.end());
  int count = 0, sum = 0;
  for (int i = 0; i < v.size(); i++) {
    if (sum + v[i] <= B) {
      sum += v[i];
      count++;
    }
  }
  cout << count;
}
