#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int a,b;
  	cin >> a >> b;
  string s;
  cin >> s;
  
  int count =0;
  for(int i=0; i<a+b+1; i++){
  	if(s[i]=='-') count++;
    }
  }
  if(s[a+1]=='-' && count==1) cout << "Yes" << endl;
	else cout << "No" << endl;
}