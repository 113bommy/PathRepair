#include <bits/stdc++.h>
using namespace std;
int temp;
int m;
int num[100];
int sum;
int score = -1;
int x, y;
int main() {
  cin >> m;
  cin >> num[0];
  for (int i = 1; i < m; i++) {
    cin >> temp;
    num[i] = num[i - 1] + temp;
  }
  cin >> x >> y;
  for (int i = 0; i < m; i++)
    if (num[i] >= x && num[i] <= y && num[m - 1] - num[i] >= x &&
        num[m - 1] - num[i] <= y)
      score = i, i = m;
  if (score != -1)
    cout << score + 2 << endl;
  else
    cout << 0 << endl;
  return 0;
}
