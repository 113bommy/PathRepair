#include <bits/stdc++.h>
using namespace std;
int sum = 0;
string word;
char let0 = 'a';
int main() {
  cin >> word;
  for (int i = 0; i < word.size(); i++) {
    if (abs(let0 - word[i]) < 12)
      sum += abs(let0 - word[i]);
    else
      sum += 25 - abs(let0 - word[i]) + 1;
    let0 = word[i];
  }
  cout << sum;
}
