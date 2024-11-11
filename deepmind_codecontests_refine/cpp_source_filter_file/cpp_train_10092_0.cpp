#include <iostream>
#include <cmath>
using namespace std;
#define EPS (1e-10)

// n := クリスタルの個数 
int n;
// (hx,hy) := 勇者の初期位置
// (dx,dy) := 魔王の位置
int hx, hy, dx ,dy;
// (cx[i],cy[i]) := i 番目のクリスタルの位置
int cx[21], cy[21];
// done[i] := i 番目のクリスタルを回収したかどうか
bool done[21];]
// 答え
bool ans;

// 2 点間の距離
double dist(double x1, double y1, double x2, double y2){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}


// 枝刈り探索
// t := 経過時間[s], (x,y) := 勇者の位置
void solve(double t, int x, int y){
    if( ans ) return ;
    
    // cnt := 現在回収したクリスタルの個数
    int cnt=0;
    for(int i=0 ; i < n ; i++ ){
        if( done[i] ) cnt++;
    }
    // n 個のクリスタルを回収したとき
    if( cnt == n ){
        ans = true;
        return;
    }
    
    // 回収できないクリスタルがあるか調べる
    for(int i=0 ; i < n ; i++ ){
        if( done[i] ) continue;
		
        double next_time = t + dist( x , y , cx[i] , cy[i] );
        // すでに回収できないクリスタルがあったら探索打ち切り
        if ( dist( dx , dy , cx[i] , cy[i] ) < next_time + EPS ){ 
            return; 
        }
    }
    for(int i=0 ; i < n ; i++ ){
        if( done[i] ) continue;
 
        double next_time = t + dist( x , y , cx[i] , cy[i] );
        done[i] = true;
        solve( next_time , cx[i] , cy[i] );
        done[i] = false;
    }
}
 
int main(){
    while( cin >> n >> hx >> hy >> dx >> dy , (n || hx || hy || dx || dy) ){
    	// (cx[i],cy[i]) := i 番目のクリスタルの位置
        for(int i=0 ; i < n ; i++ ){
            cin >> cx[i] >> cy[i];
        }
        
        // 初期化
        for(int i=0 ; i < 21 ; i++ ){
            done[i] = false;
        }
        
        ans = false;
        solve( 0.0 , hx , hy );
        if( ans ){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}