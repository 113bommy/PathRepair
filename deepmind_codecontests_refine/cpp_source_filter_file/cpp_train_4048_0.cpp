#include <iostream>
#include <string> 
using namespace std;

int main(){
	int w,h;
	string m[110];
	bool f[110][110], flag;
	
	while( cin >> h >> w , w, h ){
		flag = false;
		for(int y=0 ; y<h ; y++){
			m[y].clear();
			for(int x=0 ; x<w ; x++){
				f[y][x] = false;
			}
		}
		for(int y=0 ; y<h ; y++){
			cin >> m[y];
		}
		int x=0, y=0;
		while(1){
			if( m[y][x]=='>' ) x++;
			if( m[y][x]=='<' ) x--;
			if( m[y][x]=='v' ) y++;
			if( m[y][x]=='^' ) y--;
			
			if( m[y][x]=='.' || f[y][x] ){
				( f[y][x] )? flag = true : ;
				break;
			}
			f[y][x] = true;
		}
		(flag)? (cout << "LOOP" << endl) : (cout << x << " " << y << endl); 
	}
	return 0;
}