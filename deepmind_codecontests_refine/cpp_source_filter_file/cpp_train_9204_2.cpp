#include <bits/stdc++.h>
using namespace std;
deque<int> dq[110];
int mid[110];
int main() {
  int piles, num, i, j;
  int ans1 = 0, ans2 = 0;
  int pos;
  int ele;
  cin >> piles;
  for (i = 0; i < piles; i++) {
    cin >> num;
    for (j = 0; j < num; j++) {
      cin >> ele;
      dq[i].push_back(ele);
    }
  }
  for (i = 0; i < piles; i++) {
    num = dq[i].size();
    for (j = 1; j <= num / 2; j++) {
      ans1 += dq[i].front();
      dq[i].pop_front();
      ans2 += dq[i].back();
      dq[i].pop_back();
    }
  }
  j = 0;
  for (i = 0; i < piles; i++) {
    if (!dq[i].empty()) {
      mid[j] = dq[i].front();
      j++;
    }
  }
  j--;
  sort(mid, mid + j);
  while (j >= 0) {
    ans1 += mid[j--];
    if (j >= 0) ans2 += mid[j--];
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
