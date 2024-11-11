#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int c =0;
  if(s == "RRS" || s =="SRR") c=2;
  else if(s == "RRR") c=3;
  else if(s == "SSS") c=0;
  else c=1
  cout << c;
}

