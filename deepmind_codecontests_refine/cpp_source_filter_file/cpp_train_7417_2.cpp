#include <bits/stdc++.h>
using namespace std;
void Solve(string pairs) {
  string first_word = "";
  for (int i = 0; i < pairs.size(); i += 2) first_word += pairs[i];
  first_word += pairs[pairs.size() - 1];
  cout << first_word;
}
int main() {
  string pairs;
  int number_of_test_cases;
  cin >> number_of_test_cases;
  for (int i = 0; i < number_of_test_cases; i++) {
    cin >> pairs;
    Solve(pairs);
  }
}
