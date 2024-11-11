#include<iostream>

int main(){
	int n;
	while(std::cin>>n){
		int ans=0,data[12],back[12];
		if(n==0)break;
		for(int i=0;i<n;i++)std::cin>>data[i],back[i]=data[i];
		while(true){
			for(int i=0;i<n;i++){
				int count=0;
				for(int j=0;j<n;j++){
					if(back[i]==back[j])count++;
				}
				data[i]=count;
			}
			bool f=true;
			for(int i=0;i<n;i++){
				if(data[i]!=back[i])f=false;
			}
			if(f)break;
			for(int i=0;i<n;i++)back[i]=data[i];
			ans++;
		}
		std::cout<<ans<<std::endl;
		for(int i=0;i<n;i++){
			if(i!=n-1)std::cout<<data[i]<<" ";
			else std::cout<<data[i];
		std::cout<<std::endl;
	}
	return 0;
}