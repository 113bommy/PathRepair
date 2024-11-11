#include <iostream>
#include <string>

using namespace std;

int main(){
	string s[8];
	while(true){
		bool end = false;
		for(int i=0;i<8;i++){
			if(!(cin >> s[i])) end = true;
		}
		if(end) break;
		for(int i=0;i<8&&!end;i++){
			for(int j=0;j<8&&!end;j++){
				if(s[i][j]=='1'){
					if(i+3<8&&s[i+3][j]=='1') cout << "B" << endl;
					else if(j+3<8&&s[i][j+3]=='1') cout << "C" << endl;
					else if(i+2<8&&0<=j-1&&s[i+2][j-1]=='1') cout << "D" << endl;
					else if(i+1<8&&j+2<8&&s[i+1][j+2]=='1') cout << "E" << endl;
					else if(i+2<8&&j+1<8&&s[i+2][j+1]=='1') cout << "F" << endl;
					else if(i+1<8&&0<=j-1&&s[i+1][j-1]=='1') cout << "G" << endl;
					else cout << "A" << endl;
					end = true;
				}
			}
		}
	}
}