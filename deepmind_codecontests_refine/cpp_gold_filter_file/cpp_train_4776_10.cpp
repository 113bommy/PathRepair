#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string inStr, buf;
	int cnt =0;
	while(cin>>inStr, !cin.eof()) {
		buf = inStr;
		reverse(inStr.begin(), inStr.end());
		if(buf == inStr) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}