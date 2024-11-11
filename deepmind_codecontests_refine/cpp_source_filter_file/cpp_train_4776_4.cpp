#include <iostream>
#include <string>

using namespace std;

int main(){
	string pal;
	int count = 0;
	
	while(cin >> pal){
		bool ispalin = true;
		int l = pal.length;		
		for(int i=0;i*2 < l-1;i++) if(pal[i] != pal[l-1-i]) {ispalin = false;break;}
		if(ispalin) count++;
	}
	
	cout << count << endl;
	
	return 0;
}