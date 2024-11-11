#inlcude <iostream>
using namespace std;


int main(){
	string s; cin >> s;
	int s = 0;
	for(int i = 0; i < s.size(); i++){
		s += s[i] - '0';
	}
	cout << ((s % 9 == 0) ? "Yes" : "No") << endl;
}
