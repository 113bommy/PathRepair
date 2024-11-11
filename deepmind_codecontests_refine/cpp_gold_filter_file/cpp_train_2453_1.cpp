#include <bits/stdc++.h>
using namespace std;
string OAO;
string QAQ;
int week, ans;
int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
void test(int i) {
  int week2;
  if (QAQ[0] == 'm' && QAQ[1] == 'o') week2 = 1;
  if (QAQ[0] == 't' && QAQ[1] == 'u') week2 = 2;
  if (QAQ[0] == 'w' && QAQ[1] == 'e') week2 = 3;
  if (QAQ[0] == 't' && QAQ[1] == 'h') week2 = 4;
  if (QAQ[0] == 'f' && QAQ[1] == 'r') week2 = 5;
  if (QAQ[0] == 's' && QAQ[1] == 'a') week2 = 6;
  if (QAQ[0] == 's' && QAQ[1] == 'u') week2 = 0;
  ans |= (week + months[i] % 7) % 7 == week2;
}
int main() {
  while (cin >> OAO) {
    cin >> QAQ;
    ans = 0;
    if (OAO[0] == 'm' && OAO[1] == 'o') week = 1;
    if (OAO[0] == 't' && OAO[1] == 'u') week = 2;
    if (OAO[0] == 'w' && OAO[1] == 'e') week = 3;
    if (OAO[0] == 't' && OAO[1] == 'h') week = 4;
    if (OAO[0] == 'f' && OAO[1] == 'r') week = 5;
    if (OAO[0] == 's' && OAO[1] == 'a') week = 6;
    if (OAO[0] == 's' && OAO[1] == 'u') week = 0;
    for (int i = 0; i < 11; i++) {
      test(i);
    }
    printf(ans ? "YES" : "NO");
    puts("");
  }
  return 0;
}
