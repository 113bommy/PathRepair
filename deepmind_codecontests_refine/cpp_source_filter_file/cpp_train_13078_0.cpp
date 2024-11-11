#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
#pragma warning(disable : 4996)
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> num(n);
  vector<int> line(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &line[i]);
    if (i != 0) {
      line[i] += line[i - 1];
    }
  }
  vector<int> rotates;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n - i; j++) {
      if (i == 0)
        rotates.push_back(abs(360 - 2 * line[j - 1]));
      else
        rotates.push_back(abs(360 - 2 * (line[j + i - 1] - line[i])));
    }
  }
  sort(rotates.begin(), rotates.end());
  if (rotates.empty() && n == 1)
    cout << 360;
  else if (n == 2)
    cout << abs(360 - 2 * line[0]);
  else
    cout << rotates[0];
}
