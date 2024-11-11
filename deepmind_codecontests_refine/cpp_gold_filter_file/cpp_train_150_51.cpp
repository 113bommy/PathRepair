#include <bits/stdc++.h>
using namespace std;
int main() {
  int len;
  cin >> len;
  char *string = new char[len + 1];
  cin.ignore();
  cin.getline(string, len + 1);
  int count;
  for (int i = 1; i < len; i++) {
    int arr = 0;
    count = 0;
    for (int j = 0; j < len; j += i) {
      if (string[j] == '*')
        count++;
      else {
        count = 0;
        j = ++arr - i;
      }
      if (count == 5) {
        cout << "yes";
        return 0;
      }
    }
  }
  cout << "no";
}
