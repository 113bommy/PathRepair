#include <bits/stdc++.h>
using namespace std;
typedef struct Node {
  string str;
  int length;
} Node;
int main() {
  Node node[5000];
  int maxLen = 0, i = 0, index;
  while (getline(cin, node[i].str, '\n') && i < 5000) {
    node[i].length = node[i].str.length();
    maxLen = maxLen > node[i].length ? maxLen : node[i].length;
    i++;
  }
  index = i;
  for (i = 0; i < maxLen + 2; i++) {
    cout << "*";
  }
  cout << endl;
  int k = 1;
  for (i = 0; i < index; i++) {
    cout << "*";
    int num = maxLen - node[i].length;
    if (num % 2 == 0) {
      for (int j = 0; j < num / 2; j++) cout << " ";
      cout << node[i].str;
      for (int j = 0; j < num / 2; j++) cout << " ";
    } else {
      k++;
      for (int j = 0; j < num / 2 + k % 2; j++) cout << " ";
      cout << node[i].str;
      for (int j = 0; j < num / 2 + (k + 1) % 2; j++) cout << " ";
    }
    cout << "*" << endl;
  }
  for (i = 0; i < maxLen + 2; i++) {
    cout << "*";
  }
  cout << endl;
  return 0;
}
