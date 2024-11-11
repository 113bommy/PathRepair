#include <iostream>
#include <string>

using namespace std;

int main(){
	int i,m,h;
	string str;
	while(1){
		cin >> str;
		if(str=="-") break;
		cin >> m;
		for(i=0;i<m;i++){
			cin >> h;
			string right = str.substr(0,h);
			string left = str.substr(h);
			str = left + right;
		}
		cout << str << end1;
	}
	return 0;
}