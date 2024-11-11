#include<iostream>
using namespace std;

int main(){
	string ans,s;
	cin >> s;

	for (int i = 0; i < s.size(); i++){
		if(s[i] == '0')
			ans += '0';
		else if(s[i] == '1')
			ans += '1';
		else if(s[i] == 'B' && s[i] != "")
			ans.pop_back();
	}
	cout << ans << endl;
}