#include <bits/stdc++.h>
using namespace std;
struct node {
  int x;
  int y;
} input[10];
bool cmp(node n1, node n2) {
  if (n1.x == n2.x)
    return n1.y < n2.y;
  else
    return n1.x < n2.x;
}
int main() {
  bool judge_x_legal();
  bool judge_y_legal();
  int i, j;
  while (cin >> input[0].x >> input[0].y) {
    for (i = 1; i < 8; i++) cin >> input[i].x >> input[i].y;
    sort(input, input + 8, cmp);
    if (judge_x_legal() == true && judge_y_legal() == true)
      cout << "respectable" << endl;
    else
      cout << "ugly" << endl;
  }
  return 0;
}
bool judge_x_legal() {
  vector<int> temp;
  int i, l = 8;
  for (i = 0; i < l; i++) {
    int cot = 0, j = i;
    while (j < l && input[j].x == input[i].x) {
      cot++;
      j++;
    }
    i = j - 1;
    temp.push_back(cot);
  }
  if (temp.size() == 3) {
    if (temp[0] == 3 && temp[1] == 2 && temp[2] == 3)
      return true;
    else
      return false;
  } else
    return false;
}
bool judge_y_legal() {
  vector<int> temp1, temp2;
  int i;
  for (i = 0; i < 3; i++) temp1.push_back(input[i].y);
  for (i = 5; i < 8; i++) temp2.push_back(input[i - 5].y);
  for (i = 0; i < 3; i++) {
    if (temp1[i] != temp2[i]) return false;
  }
  for (i = 0; i < 2; i++) {
    if (input[i].y == input[i + 1].y) return false;
  }
  if (input[3].y == input[0].y && input[4].y == input[2].y)
    return true;
  else
    return false;
}
