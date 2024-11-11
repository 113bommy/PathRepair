#include <iostream>
using namespace std;

int main(){
	int H,W;
	cin >> H;
	cin >> W;
	char grid[55][55];
	int cnt,i,j;
	cnt = 0;
	for( i=1; i <= H; ++i){
		for( j=1; j <= W; ++j){
			cin >> grid[i][j];
		}
	}
	for( i=1; i <= H; ++i){
		for( j=1; j <= W; ++j){
			if(c[i][j]=='#' 
			&& c[i-1][j] != '#'
			&& c[i][j-1] != '#'
			&& c[i+1][j] != '#'
			&& c[i][j+1] != '#'
			) ++cnt;
		}
	}
	if (cnt > 0){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}

	return 0;
}
