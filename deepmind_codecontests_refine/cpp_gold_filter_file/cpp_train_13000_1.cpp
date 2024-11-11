#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int h,w;
string s[100];

void newland(int i, int j) {
  char t = s[i][j];
  s[i][j] = '.';
  if(j!=w-1 && t == s[i][j+1]) newland(i,j+1);
  if(i!=h-1 && t == s[i+1][j]) newland(i+1,j);
  if(j!=0 && t == s[i][j-1]) newland(i,j-1);
  if(i!=0 && t == s[i-1][j]) newland(i-1,j);
}

void solve() {
  int i,j;
  while(1) {
    int n=0;
    cin >> h >> w;
    if(h==0) break;
    for(i=0 ; i<h ; i++) {
      cin >> s[i];
    }
    for(i=0 ; i<h ; i++) {
      for(j=0 ; j<w ; j++) {
	if(s[i][j]!='.') {
	  newland(i,j);
	  n++;
	}
      }
    }
    cout << n << endl;
  }
}

int main(void) {
  solve();
  return 0;
}