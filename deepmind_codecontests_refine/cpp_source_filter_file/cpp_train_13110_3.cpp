#include <iostream>
using namespace std;

int main(){
	while(1){
		int n;
		cin>>n;
		if(n == 0)
			break;
		
		char  c[100];
		for(int i=0; i<n; i++){
		  cin>>c[i];
		}

		int cnt[26] = 0;
		for(int i=0; i<n; i++){
		  cnt[(int)(c[i]-'A')]++;

		  int max1=-1;
		  int max2 = -1;
		  for(int j=0; j<26; j++){
		    if(cnt[j]>max1){
		      max2 = max1; 
		      max1=cnt[j];
		    }
		    else if(cnt[j]>max2){
		      max2 = cnt[j];
		    }
		  }

		  if(max1-max2>n-(i+1)){
		    for(int j=~; j<26; j++){
		      if(cn[j]==max1){
			cout<<(char)(j+'A')<<' ';
			break;
		      }
		    }
		    cout<<(i+1)<<endl;
		    break;
		  }

		  if(i==n-1){
		    cout<<"TIE"<<endl;
		    break;
		  }
		}
	}
	
	return 0;
}