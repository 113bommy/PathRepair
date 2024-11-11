#include <bits/stdc++.h>
using namespace std;
vector<int> letter;
vector<int> indexletter;
int main() {
  int n;
  int op = 0;
  int unread = 0;
  scanf("%d", &n);
  letter.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &letter[i]);
    if (letter[i] == 1) indexletter.push_back(i);
  }
  for (int i = 0; i < indexletter.size(); i++) {
    op++;
    if (i < indexletter.size() - 1 && indexletter[i + 1] - indexletter[i] >= 2)
      op++;
  }
  printf("%d\n", op);
  return 0;
}
