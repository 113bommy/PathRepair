#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int max = 2000000001, min = -2000000001;
  long long int x, y;
  string question;
  char answer;
  int i;
  for (i = 0; i < n; i++) {
    int tmp;
    cin >> question;
    cin >> x >> answer;
    cin.get();
    if (question[0] == '<') {
      if (answer == 'Y') {
        if (x < max)
          if (question.size() == 2)
            max = x;
          else
            max = x - 1;
      } else {
        if (x > min)
          if (question.size() == 2)
            min = x + 1;
          else
            min = x;
      }
    } else {
      if (question[0] == '>') {
        if (answer == 'Y') {
          if (x > min)
            if (question.size() == 2)
              min = x;
            else
              min = x + 1;
        } else {
          if (x < max)
            if (question.size() == 2)
              max = x - 1;
            else
              max = x;
        }
      }
    }
  }
  if (min > max) {
    cout << "Impossible" << endl;
    return 0;
  } else {
    if (max == min)
      cout << min << endl;
    else
      cout << min + 1 << endl;
  }
  return 0;
}
