#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	long long k;
	cin >> s >> k;

	for(int i=0; i<k; i++){
		if(s[i] != '1' || i==k-1){
			cout << s[i] << endl;
			break;
		}
	}
}
