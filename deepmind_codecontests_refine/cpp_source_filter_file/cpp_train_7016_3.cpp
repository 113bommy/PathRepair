#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  set<int> a, b;
  set<int>::iterator it;
  int x[10], y[10];
  int X[10], Y[10];
  for (int i = 1; i <= 8; i++) {
    cin >> x[i] >> y[i];
    a.insert(x[i]);
    b.insert(y[i]);
  }
  int flag = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = i + 1; j <= 8; j++) {
      if (x[i] == x[j] && y[i] == y[j]) flag++;
    }
  }
  if (a.size() != 3 || b.size() != 3) flag++;
  int s = 0;
  for (it = a.begin(); it != a.end(); it++) {
    s++;
    X[s] = *it;
  }
  s = 0;
  for (it = b.begin(); it != b.end(); it++) {
    s++;
    Y[s] = *it;
  }
  int count1 = 0, count2 = 0;
  for (int i = 1; i <= 8; i++)
    if (x[i] == X[1]) count1++;
  for (int i = 1; i <= 8; i++)
    if (x[i] == X[3]) count2++;
  if (count1 != 3 || count2 != 3) flag++;
  count1 = 0;
  count2 = 0;
  for (int i = 1; i <= 8; i++)
    if (y[i] == X[1]) count1++;
  for (int i = 1; i <= 8; i++)
    if (y[i] == X[3]) count2++;
  if (count1 != 3 || count2 != 3) flag++;
  for (int i = 1; i <= 8; i++) {
    if (x[i] == X[2] && y[i] == Y[2]) flag++;
  }
  if (flag > 0)
    cout << "ugly" << endl;
  else
    cout << "respectable" << endl;
  return EXIT_SUCCESS;
}
