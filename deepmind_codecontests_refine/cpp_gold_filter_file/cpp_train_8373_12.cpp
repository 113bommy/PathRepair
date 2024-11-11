#include <bits/stdc++.h>
using namespace std;
int arr[200];
int main() {
  char heading[1500];
  char text[1500];
  cin.getline(heading, 1000);
  cin.getline(text, 1000);
  for (int i = 0; i < strlen(heading); i++) {
    arr[heading[i]]++;
  }
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] != ' ') {
      arr[text[i]]--;
      if (arr[text[i]] < 0) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
