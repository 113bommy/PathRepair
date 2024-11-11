#include <bits/stdc++.h>
using namespace std;
int arr[10000];
vector<int> segTree[3 * 10000 + 10];
void createTree(int idx, int start, int end) {
  if (start == end) {
    segTree[idx].push_back(arr[start]);
    return;
  }
  int mid = (start + end) / 2;
  createTree(2 * idx + 1, start, mid);
  createTree(2 * idx + 2, mid + 1, end);
  int i, j;
  i = 0;
  j = 0;
  int l = 2 * idx + 1;
  int r = 2 * idx + 2;
  while (i != segTree[l].size() || j != segTree[r].size()) {
    if (j == segTree[r].size() ||
        (i < segTree[l].size() && segTree[l][i] < segTree[r][j])) {
      segTree[idx].push_back(segTree[l][i]);
      i++;
    } else {
      segTree[idx].push_back(segTree[r][j]);
      j++;
    }
  }
}
void printTree(int idx, int start, int end) {
  cout << idx << " " << start << " " << end << ":"
       << "(" << segTree[idx].size() << ")";
  for (int i = 0; i < segTree[idx].size(); i++) cout << segTree[idx][i] << " ";
  cout << endl;
  int mid = (start + end) / 2;
  if (start != end) {
    printTree(2 * idx + 1, start, mid);
    printTree(2 * idx + 2, mid + 1, end);
  }
}
int binSearch(vector<int> &data, int start, int end, int val) {
  if (data[start] > val) return 0;
  if (start >= end) return (start + 1);
  int mid = (start + end) / 2;
  if (data[mid] <= val && data[mid + 1] > val) return (mid + 1);
  if (data[mid] < val)
    return binSearch(data, mid + 1, end, val);
  else
    return binSearch(data, start, mid - 1, val);
}
int query(int startQ, int endQ, int val, int idx, int start, int end) {
  if (startQ <= start && endQ >= end) {
    int count = binSearch(segTree[idx], 0, segTree[idx].size() - 1, val);
    return count;
  }
  if (endQ < start || startQ > end) return 0;
  int mid = (start + end) / 2;
  int count = 0;
  count += query(startQ, endQ, val, 2 * idx + 1, start, mid);
  count += query(startQ, endQ, val, 2 * idx + 2, mid + 1, end);
  return count;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  createTree(0, 0, n - 1);
  for (int i = 0; i < m; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    a--;
    b--;
    x--;
    int pos = query(a, b, arr[x], 0, 0, n - 1);
    if (pos == x - a + 1)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
