#include<iostream>
#include<vector>
#include<map>
using namespace std;
main(){
  //mlÛ¶vÛ¶
  long long a,b,c,n,f;
  //aÔbP¿cÊ
  while(cin>>n,n){
		map<int,long long> m;
		vector<int> v;
		f=1;
    for(;n;n--){
			cin>>a>>b>>c;
      if(!m[a])v.push_back(a);
      m[a] += b*c;
    }
    
    for(int i=0;i<v.size();i++)
			if(m[v[i]]>999999)f=0,cout<<v[i]<<endl;
    f?:cout<<"NA"<<endl;
  }
}