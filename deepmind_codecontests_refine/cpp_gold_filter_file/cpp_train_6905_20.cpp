#include <bits/stdc++.h>
using namespace std;
int main() {
  string Aux, Text;
  bool Amplify = false, Analyze, First = true, InsertSpace = false;
  while (getline(cin, Aux, '\n')) {
    Amplify = false;
    Analyze = false;
    for (int i = 0; i < Aux.length() && Analyze == false; i++) {
      if (Aux[i] == ' ')
        continue;
      else if (Aux[i] == '#') {
        Amplify = true;
        Analyze = true;
      } else {
        Amplify = false;
        Analyze = true;
      }
    }
    if (Amplify) {
      if (First == true)
        Text += Aux;
      else
        Text += "\n" + Aux;
      InsertSpace = true;
    } else {
      if (InsertSpace) {
        Text.push_back('\n');
        InsertSpace = false;
      }
      for (int i = 0; i < Aux.length(); i++) {
        if (Aux[i] != ' ' && Aux[i] != '\n' && Aux[i] != '\0')
          Text.push_back(Aux[i]);
      }
    }
    First = false;
  }
  cout << Text << endl;
  return 0;
}
