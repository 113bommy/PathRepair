#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>

using namespace std;

int main(){
		int n,num,cont,v;
		string a,nex;
				stringstream ss;
				char bin[100];
	while(1){
		
		scanf("%d",&n);
		
		if(n==0){break;}
		cin>>a;
		
		for(int i=0;i<n;i++){
			cont=0;
			while(1){
				if(cont>=a.size()){break;}
				
				num=a[cont];
				
				v=0;
				while(1){
					if(a[cont]!=num){break;}
					v++;
					cont++;
				}
				/*
				ss.str("");
				ss<<v;*/
				
				sprintf(bin,"%d",v);
				nex+=bin;
				
				//nex+=ss.str();
				nex+=num;
			}
			a=nex;
			nex="";
		}
			cout<<a<<endl;
	}
}