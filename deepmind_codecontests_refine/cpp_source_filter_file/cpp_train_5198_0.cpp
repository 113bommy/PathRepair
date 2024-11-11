#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <stdio.h>
using namespace std;
string s;
long long ans;
int cur;
long long suu(){
  string num = "";
  while(cur < s.size() && '0' <= s[cur] && s[cur] <= '9' ){
	fflush(stdout);
	num += s[cur];
	cur++;
  }

  return stoll(num);
}
long long kou(){
  long long res = suu();
  if(cur < s.size() && s[cur] == '*'){
	cur++;
	res *= kou();
  }
  return res;
}
long long siki(){
  long long res = kou();	
  if(cur < s.size() && s[cur] == '+'){
	cur++;
	res += siki()

  }
  return res;
}
long long left_siki(){
  long long res = suu();
  char op;
  while( cur < s.size() && ((op = s[cur]) == '+' || (op == '*') ) ){
	cur++;
	if(op == '+'){
	  res += suu();
	}else if(op == '*'){
	  res *=  suu();
	}
  }
  return res;
}
int main(){
  cur = 0;
  cin >> s >> ans;
  long long res1 = siki();

  cur = 0;
  long long res2 = left_siki();
  
  int flag = 0;
  if(res1 == ans){
	flag = 1;
  }
  if(res2 == ans){
	flag |= 2;
  }

  if(flag == 0)cout << "I" << endl;
  else if(flag == 3)cout << "U" << endl;
  else if(flag == 1) cout << "M" << endl;
  else if(flag == 2) cout << "L" << endl;
  
  return 0;
  
}