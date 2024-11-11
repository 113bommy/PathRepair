#include <bits/stdc++.h>
using namespace std;
int n, A[1000005];
pair<int, int> B[1000005];
int main() {
  cin >> n;
  int i, k, left, right;
  for (i = 1; i <= n; i++) {
    cin >> A[i];
    B[i] = make_pair(A[i], i);
  }
  left = 0;
  int pos[3], no[3];
  while (left < n) {
    while (left + 1 <= n && A[left + 1] == 0) {
      left++;
      cout << "0\n";
    }
    if (left == n) break;
    left++;
    right = left;
    while (right <= n && A[right]) right++;
    right--;
    if (right < n) {
      sort(B + left, B + right + 1);
      memset(pos, -1, sizeof(pos));
      memset(no, 0, sizeof(no));
      for (i = right; i > right - 3 && i >= left; i--)
        pos[right - i] = B[i].second;
      for (i = left; i <= right; i++) {
        if (i == pos[0])
          cout << "pushFront\n", no[0] = 1;
        else if (i == pos[1])
          cout << "pushQueue\n", no[1] = 1;
        else if (i == pos[2])
          cout << "pushStack\n", no[2] = 1;
        else
          cout << "PushBack\n";
      }
      k = no[0] + no[1] + no[2];
      cout << k;
      for (i = 1; i <= k; i++) {
        if (i == 1) cout << " popFront";
        if (i == 2) cout << " popQueue";
        if (i == 3) cout << " popStack";
      }
      cout << "\n";
    } else {
      for (i = left; i <= right; i++) cout << "pushStack\n";
    }
    left = right + 1;
  }
  return 0;
}
