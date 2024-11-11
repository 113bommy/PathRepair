#include <iostream>
using namespace std;

int main() {
	int f, b , cnt = 0;
	string s;
	cin >> s;
	f = 0, b = s.size() - 1;
	while(l<=b){
	  if(s[f] == s[b]){//端が一致で無視.
	  	f++;
	  	b--;
	  }
	  else if((s[f] != 'x') && (s[b] != 'x')){
	  	cout << -1 << endl;
	  	return 0;
	  }
	  else if(s[f] == 'x'){
	  	cnt++;
	  	f++;
	  }
	  else{//s[b] == 'x'
	  	cnt++;
	  	r--;
	  }
	}
	cout << cnt << endl;
	return 0;
}