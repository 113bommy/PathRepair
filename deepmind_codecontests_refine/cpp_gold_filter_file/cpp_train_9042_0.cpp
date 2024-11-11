#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin >> n , n) {
    int mass[20][20]={0};
    int nowx = n / 2;
    int nowy = nowx + 1;
    int limit = n * n + 1;
    int cou = 2;
    mass[nowy][nowx] = 1;
    while(cou != limit) {
      if(mass[(nowy+1)%n][(nowx+1)%n] == 0){
	nowy = (nowy + 1) % n;
	nowx = (nowx + 1) % n;
	mass[nowy][nowx] = cou;
      }
      else {
	nowy = (nowy + 1) % n;
	nowx = (nowx + 1) % n;
	nowy = (nowy + 1) % n;
	if(nowx - 1 == -1) nowx = n - 1;
	else nowx = nowx - 1;
	mass[nowy][nowx] = cou;
      }
      cou++;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	printf("%4d",mass[i][j]);
      }
      cout << endl;
    }
  }
}
    