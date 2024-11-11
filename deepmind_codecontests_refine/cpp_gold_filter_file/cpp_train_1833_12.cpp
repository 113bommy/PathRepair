#include <bits/stdc++.h>
using namespace std;
struct node {
  int val;
  int index;
} x[200005], y[200005];
bool compare(node one, node two) { return one.val < two.val; }
void solvelt(int n, node arr[], int ans[]) {
  int i, j, done = 0, pre = -1, counter[n];
  for (i = 0; i < n; i++) {
    counter[i] = 0;
  }
  for (i = 0; i < 2 * n; i++) {
    if (pre != arr[i].val) {
      pre = arr[i].val;
      for (j = i; j < 2 * n; j++) {
        if (arr[j].val > pre) {
          break;
        }
        counter[arr[j].index] += 1;
        if (counter[arr[j].index] == 2) {
          done++;
        }
      }
    }
    if (ans[arr[i].index] == 0) {
      ans[arr[i].index] = n - done;
      if (counter[arr[i].index] != 2) {
        ans[arr[i].index]--;
      }
    }
  }
}
void solverd(int n, node arr[], int ans[]) {
  int i, j, done = 0, pre = -1, counter[n];
  for (i = 0; i < n; i++) {
    counter[i] = 0;
  }
  for (i = 2 * n - 1; i >= 0; i--) {
    if (pre != arr[i].val) {
      pre = arr[i].val;
      for (j = i; j >= 0; j--) {
        if (arr[j].val != pre) {
          break;
        }
        counter[arr[j].index] += 1;
        if (counter[arr[j].index] == 2) {
          done++;
        }
      }
    }
    if (ans[arr[i].index] == 0) {
      ans[arr[i].index] = n - done;
      if (counter[arr[i].index] != 2) {
        ans[arr[i].index]--;
      }
    }
  }
}
int main() {
  int d, n, m, x1, x2, y1, y2, i, j = 0;
  cin >> d;
  cin >> n >> m;
  for (i = 0; i < d; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    x[j].val = x1;
    x[j + 1].val = x2;
    y[j].val = y1;
    y[j + 1].val = y2;
    x[j].index = x[j + 1].index = y[j].index = y[j + 1].index = i;
    j += 2;
  }
  sort(x, x + j, compare);
  sort(y, y + j, compare);
  int left[d], right[d], top[d], down[d];
  for (i = 0; i < d; i++) {
    left[i] = right[i] = top[i] = down[i] = 0;
  }
  solvelt(d, x, left);
  solverd(d, x, right);
  solvelt(d, y, top);
  solverd(d, y, down);
  cin >> x1 >> x2 >> y1 >> y2;
  for (i = 0; i < d; i++) {
    if (right[i] == x1 && left[i] == x2 && down[i] == y1 && top[i] == y2) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
