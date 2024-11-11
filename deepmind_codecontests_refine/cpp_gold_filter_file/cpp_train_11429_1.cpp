#include <iostream>
using namespace std;

int main(){
	string s, t;
  	cin >> s >> t;
  	t.pop_back();
  
  	if (s == t) cout << "Yes" << endl;
  	else cout << "No" << endl;
}