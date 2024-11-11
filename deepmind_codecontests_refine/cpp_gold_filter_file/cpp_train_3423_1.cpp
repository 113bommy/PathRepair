#include<bits/stdc++.h>

using namespace std;

int main(){

  double l;
  double r;

  int l_a=0;
  int l_b=0;
  int l_c=0;
  int l_d=0;
  int r_a=0;
  int r_b=0;
  int r_c=0;
  int r_d=0;
  
  while(cin>>l>>r){

	if(l>=1.1)
	  l_a++;
	else if(l>=0.6 && l<1.1)
	  l_b++;
	else if(l>=0.2 && l<0.6)
	  l_c++;
	else if(l<0.2)
	  l_d++;

	if(r>=1.1)
	  r_a++;
	else if(r>=0.6 && r<1.1)
	  r_b++;
	else if(r>=0.2 && r<0.6)
	  r_c++;
	else if(r<0.2)
	  r_d++;
	
  }

  cout<<l_a<<" "<<r_a<<endl;
  cout<<l_b<<" "<<r_b<<endl;
  cout<<l_c<<" "<<r_c<<endl;
  cout<<l_d<<" "<<r_d<<endl;
  
}

