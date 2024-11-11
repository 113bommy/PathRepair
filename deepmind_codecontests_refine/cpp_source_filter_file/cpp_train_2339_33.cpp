#include <bits/stdc++.h>
using namespace std;
char f, m, c;
char players;
string config("");
void get_input(char &x) {
  string input;
  cin >> input;
  cin.ignore();
  x = input[0];
}
void printwinner(char w) {
  if (f == w) {
    cout << "F"
         << "\n";
  } else if (m = w) {
    cout << "M"
         << "\n";
  } else {
    cout << "S"
         << "\n";
  }
}
int main() {
  get_input(f);
  get_input(m);
  get_input(c);
  config = {f, m, c};
  sort(config.begin(), config.end());
  if (config == "rss") {
    printwinner('r');
  } else if (config == "prr") {
    printwinner('p');
  } else if (config == "pps") {
    printwinner('s');
  } else {
    cout << "?"
         << "\n";
  }
}
