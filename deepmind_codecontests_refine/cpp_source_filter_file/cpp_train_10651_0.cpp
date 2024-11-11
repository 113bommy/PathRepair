#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  string name;
  int taxi;
  int pizza;
  int girl;
  int pos;
} n;
n input[200];
bool cmp1(n n1, n n2) {
  if (n1.taxi == n2.taxi)
    return n1.pos < n2.pos;
  else
    return n1.taxi > n2.taxi;
}
bool cmp2(n n1, n n2) {
  if (n1.pizza == n2.pizza)
    return n1.pos < n2.pos;
  else
    return n1.pizza > n2.pizza;
}
bool cmp3(n n1, n n2) {
  if (n1.girl == n2.girl)
    return n1.pos < n2.pos;
  else
    return n1.girl > n2.girl;
}
int main() {
  bool istaxi(string input);
  bool ispizza(string input);
  int n;
  while (cin >> n) {
    int i, j;
    for (i = 0; i < n; i++) {
      int j, s;
      cin >> s >> input[i].name;
      input[i].taxi = input[i].pizza = input[i].girl = 0;
      input[i].pos = i;
      for (j = 0; j < s; j++) {
        string str;
        cin >> str;
        if (istaxi(str) == true)
          input[i].taxi++;
        else if (ispizza(str) == true)
          input[i].pizza++;
        else
          input[i].girl++;
      }
    }
    sort(input, input + n, cmp1);
    printf("If you want to call a taxi, you should call: ");
    i = 1;
    cout << input[0].name;
    while (input[i].taxi == input[0].taxi && i < n) {
      cout << "," << input[i].name;
      i++;
    }
    cout << "." << endl;
    sort(input, input + n, cmp2);
    printf("If you want to order a pizza, you should call: ");
    i = 1;
    cout << input[0].name;
    while (input[i].pizza == input[0].pizza && i < n) {
      cout << "," << input[i].name;
      i++;
    }
    cout << "." << endl;
    sort(input, input + n, cmp3);
    printf(
        "If you want to go to a cafe with a wonderful girl, you should call: ");
    cout << input[0].name;
    i = 1;
    while (input[i].girl == input[0].girl && i < n) {
      cout << "," << input[i].name;
      i++;
    }
    cout << "." << endl;
  }
  return 0;
}
bool istaxi(string input) {
  int i, j;
  for (i = 0; i < 7; i++)
    for (j = i + 1; j < 8; j++) {
      if (input[i] != '-' && input[j] != '-') {
        if (input[i] != input[j]) return false;
      }
    }
  return true;
}
bool ispizza(string input) {
  int i;
  if (input[0] > input[1] && input[1] > input[3] && input[3] > input[4] &&
      input[4] > input[6] && input[6] > input[7])
    return true;
  else
    return false;
}
