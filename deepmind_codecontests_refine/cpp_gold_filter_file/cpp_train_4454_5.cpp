#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	string s;
  cin >> s;
  int sum = 0;
  for(auto x : s) {
  	sum = (sum + x - '0')%9;
  }
  cout << (sum ? "No" : "Yes");
}