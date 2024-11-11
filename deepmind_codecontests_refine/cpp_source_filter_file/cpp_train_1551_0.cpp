#include <iostream>
using namespace std;
#define F(i,n) for( int i = 0; i < n; i++ )

char graph[6][2] = {
  // fで失敗
  { 'x', 'y' }, // a
  { 'f', 'z' }, // x
  { 'x', 'f' }, // y
  { 'w', 'b' }, // z
  { 'b', 'y' }, // w
  { 'y', 'x' }  // b    
};

bool simulate( string s ){
  char now = 'a';
  F( i, s.size() ){
    int next = s[i] == '0' ? 0 : 1;
    int nowIndex;
    if( now == 'a' ){ nowIndex = 0; }
    else if( now == 'x' ){ nowIndex = 1; }
    else if( now == 'y' ){ nowIndex = 2; }
    else if( now == 'z' ){ nowIndex = 3; }
    else if( now == 'w' ){ nowIndex = 4; }
    else if( now == 'b' ){ nowIndex = 5; }
    now = graph[ nowIndex ][ next ];
    if( now == 'f'){ return false; }
  }
  if( now == 'b' ){ return true; }
  else return false;
}

main(){
  string s;
  while( cin >> s && s != "#" ){
    if( simulate( s ) ){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }