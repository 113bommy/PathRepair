#include <bits/stdc++.h>
using namespace std;
char in[100005];
char ans[100005];
int main() {
  cin >> in;
  int index = 0;
  while (in[index] != 0) index++;
  int size = index;
  index--;
  char cur = 'a' - 1;
  int count_ans = 0;
  while (index >= 0) {
    if (in[index] >= cur) {
      ans[count_ans++] = in[index];
      cur = in[index];
    }
    index--;
  }
  for (int i = 0; i <= (count_ans / 2); i++) {
    char tmp = ans[i];
    ans[i] = ans[count_ans - 1 - i];
    ans[count_ans - 1 - i] = tmp;
  }
  ans[count_ans] = 0;
  cout << ans << endl;
}
