#include <bits/stdc++.h>
using namespace std;
int graph[50][50];
string words[100];
int main() {
  int numberOfWords;
  cin >> numberOfWords;
  for (int i = 0; i < (numberOfWords); i++) {
    cin >> words[i];
    int first = 99, second = 99, third = 0;
    for (int j = 0; j < (words[i].size()); j++) {
      int key = words[i][j] - 'a';
      if (first == 99)
        first = key;
      else if (first != key && second == 99)
        second = key;
      else if (first != key && second != key)
        third = 1;
    }
    if (third == 0) {
      int a = min(first, second);
      int b = max(first, second);
      if (b != 99) {
        graph[a][b] += words[i].size();
      } else {
        for (int j = 0; j < (50); j++) {
          int a1 = min(a, j);
          int b1 = max(a, j);
          graph[a1][b1] += words[i].size();
        }
      }
    }
  }
  int max = 1;
  for (int i = 0; i < (50); i++) {
    for (int j = 0; j < (50); j++) {
      if (max < graph[i][j]) {
        max = graph[i][j];
      }
    }
  }
  cout << max << endl;
  return 0;
}
