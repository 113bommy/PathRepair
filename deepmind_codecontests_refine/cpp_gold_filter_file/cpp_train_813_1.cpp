#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  char array[60][60] = {{0}};
  for(int i=0;i<H;i++) {
    cin >> array[i];
    //cout << array[i] << endl;
  }
  for(int i=0;i<H;i++) {
    for(int j=0;j<W;j++) {
      if(array[i][j] == '.') {
	int sum=0;
	for(int l=-1;l<=1;l++) {
	  for(int m=-1;m<=1;m++) {
	    if((l==0 && m==0) || i+l<0 || j+m<0) continue;
	    else if(array[i+l][j+m] == '#') sum++;
	  }
	}
	//cout << sum << endl;
	array[i][j] = sum + '0';
      }
    }
    cout << array[i] << endl;
  }
}
      