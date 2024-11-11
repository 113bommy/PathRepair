#include <bits/stdc++.h>
using namespace std;
int main() {
  long int number, temp, count = 0, answer = 0;
  cin >> number;
  while (number--) {
    cin >> temp;
    if (temp == 1)
      count++;
    else
      answer += count;
  }
  cout << answer;
  return 0;
}
