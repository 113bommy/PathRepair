#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  if (s.size()==3) swap(s[0],s[2]);
  cout << s << endl;
}
