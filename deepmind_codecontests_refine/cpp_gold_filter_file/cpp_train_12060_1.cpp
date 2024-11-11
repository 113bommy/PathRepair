#include<iostream>
using namespace std;
int main(void){
  string s;
  cin >> s;
  cout << s.erase(s.size() - 8,8);
}