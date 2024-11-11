#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
  	cin >> a >> b;
  	int s = atoi((a+b).c_str())
  	int t = (int)sqrt(s);
  
  	puts(t*t==s?"Yes":"No");
  
	return 0;
}