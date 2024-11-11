#include <bits/stdc++.h>
void File_IO() {}
using namespace std;
int main() {
  File_IO();
  int n, s;
  cin >> n >> s;
  int back = -1000000;
  int forward = 0;
  int time[n + 2];
  time[0] = -1000000;
  for (int i = 1; i <= n; i++) {
    int h, m;
    cin >> h >> m;
    time[i] = h * 60 + m;
  }
  time[n + 1] = time[n] + s - 1;
  int cur = 0;
  int i = 1;
  while (1) {
    if (cur + s < time[i] && cur - s > time[i - 1]) {
      if (cur)
        cout << cur / 60 << " " << cur % 60 << endl;
      else
        cout << "0 0\n";
      return 0;
    } else
      cur++;
    if (cur >= time[i]) i++;
  }
}
