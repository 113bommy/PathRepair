#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,x;
  cin>> A >> B;
  for(int i=A;i<B+1;i++){
  	 if(i/10000==i%10&&i/1000%10==i%100/10) x++;
     }
  	  cout << x;
}