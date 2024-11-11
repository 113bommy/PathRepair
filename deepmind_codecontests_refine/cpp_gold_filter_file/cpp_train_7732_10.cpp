#include <bits/stdc++.h>
using namespace std;
int a[110];
int n;
int score, fine;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int time = 10;
  int task = 1;
  while (time <= 720 && task <= n) {
    time += a[task];
    if (time <= 720) {
      score++;
      if (time > 360) fine += time - 360;
    }
    task++;
  }
  cout << score << " " << fine << endl;
}
