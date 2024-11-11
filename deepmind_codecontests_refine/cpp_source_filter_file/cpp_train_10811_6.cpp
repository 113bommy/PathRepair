#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, sum=0,m=0;
  string s; 
  cin >> n >> s;
  
  for(int i=0; i<n; i==){
  	if(s[i]=='I') sum++;
    else sum--;
  	m = max(m, sum);
  }
	cout << max << endl;
}