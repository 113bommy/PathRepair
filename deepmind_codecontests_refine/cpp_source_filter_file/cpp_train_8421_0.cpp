#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int main(){

	int W,Q;int x,w;
	string str;
	while(1){
		int N[101]={};
		for(int i=0;i<101;i++)
			N[i]=999;


	cin>>W>>Q;if(W==0&&Q==0)break;
	for(int i=0;i<Q;i++){
		cin>>str;
		if(str=="s"){
		cin>>x>>w;bool f=false;
		for(int I=0;I<W;I++){int L=0;if(f==true)break;
			for(int J=I;J<W;J++)
				if(N[J]==999){L++;if(L==w){f=true;cout<<I<<endl;
					for(int j=I;j<I+w;j++)
						N[j]=x;
						L=0;break;	}
					}
				else{L=0;break;}
		}
		if(f==false)cout<<"impossible"<<endl;
		}
		else{
		cin>>x;
		for(int I=0;I<101;I++)
			if(N[I]==x)N[I]=999;
		
		
		}
		//for(int I=0;I<W;I++)
			//cout<<N[I]<<endl;
	}
	cout<<END<<endl;
	}
	return 0;
	}