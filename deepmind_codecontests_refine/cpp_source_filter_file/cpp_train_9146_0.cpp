#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	
	string::size_type pos1,pos2, begin;
	
	while(1){
		pos1 = s.find("apple", begin);
		pos2 = s.find("peach", begin);
		
		if( pos1 == string::npos && pos2 == string::npos ) 
			break;
		
		if( pos1 < pos2 ){
			s.replace( pos1, 5, "peach" );
			i = pos1 + 5;
		}else{
			s.replace( pos2, 5, "apple" );
			i = pos2 + 5;
		}
	
	}
	cout << s << endl;
}