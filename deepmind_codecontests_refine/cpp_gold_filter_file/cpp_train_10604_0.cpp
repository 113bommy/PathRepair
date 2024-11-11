#include<iostream>
using namespace std;
int main(){
  string s; cin >> s;
  string x = "CODEFESTIVAL2016";
  int cnt = 0;
  for(int i = 0; i < 16; ++i)
    cnt += s[i] != x[i];
  cout << cnt << endl;
}