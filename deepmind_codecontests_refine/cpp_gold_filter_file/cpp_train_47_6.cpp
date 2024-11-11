#include <bits/stdc++.h>
using namespace std;
int maxFellTrees(const vector<long long int> &t,
                 const vector<long long int> &h) {
  long long int maxNum = 0;
  int size = t.size();
  vector<long long int> fellTree(size);
  for (size_t i = 0; i < size; i++) {
    if (i == 0) {
      maxNum++;
      fellTree[i] = t[i];
      continue;
    }
    if (i == size - 1) {
      maxNum++;
      continue;
    }
    if (t[i] - h[i] > max(fellTree[i - 1], t[i - 1])) {
      fellTree[i] = t[i] - h[i];
      maxNum++;
    } else if (t[i] + h[i] < t[i + 1]) {
      fellTree[i] = t[i] + h[i];
      maxNum++;
    }
  }
  return maxNum;
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<long long int> trees(n);
  vector<long long int> heights(n);
  for (int i = 0; i < n; i++) {
    cin >> trees[i];
    cin >> heights[i];
  }
  cout << maxFellTrees(trees, heights) << endl;
  return 0;
}
