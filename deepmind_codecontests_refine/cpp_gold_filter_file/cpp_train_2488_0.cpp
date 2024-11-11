#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct P{
	int x,y;
	P(int x_, int y_){
		x = x_; y = y_;
	}
	P(){}
};
bool exist[5001][5001];
int x[3001], y[3001];

int main(){
	int n;
	while( cin >> n , n ){
		for(int i=0 ; i < 5001 ; i++ ){
			for(int j=0 ; j < 5001 ; j++ ){
				exist[i][j] = false;
			}
		}
		for(int i=0 ; i < n ; i++ ){
			cin >> x[i] >> y[i];
			exist[y[i]][x[i]] = true;
		}
		int ans = 0;
		for(int i=0 ; i < n ; i++ ){
			for(int j=i+1 ; j < n ; j++ ){
				P p1 = P( x[i] , y[i] );
				P p2 = P( x[j] , y[j] );
				int dx = abs(p1.x - p2.x);
				int dy = abs(p1.y - p2.y);
				P p3( p2.x - dy , p2.y + dx );
				P p4( p1.x - dy , p1.y + dx );
				if( p3.x < 0 || p3.x > 5000 || p3.y < 0 || p3.y > 5000 ) continue;
				if( p4.x < 0 || p4.x > 5000 || p4.y < 0 || p4.y > 5000 ) continue;
				if( exist[p3.y][p3.x] && exist[p4.y][p4.x] ){
					ans = max( ans , dx*dx + dy*dy );
				}
				p3 = P( p1.x + dy , p1.y - dx );
				p4 = P( p2.x + dy , p2.y - dx );
				if( p3.x < 0 || p3.x > 5000 || p3.y < 0 || p3.y > 5000 ) continue;
				if( p4.x < 0 || p4.x > 5000 || p4.y < 0 || p4.y > 5000 ) continue;
				if( exist[p3.y][p3.x] && exist[p4.y][p4.x] ){
					ans = max( ans , dx*dx + dy*dy );
				}
			}
		}
		cout << ans << endl;
	}
}