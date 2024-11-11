#include<bits/stdc++.h>
using namespace std;
string S;
int main(){
	int n;
	while(true){
		cin>>n;vector<string>vec;
		vector<pair<int,string> >w;
		if(n==0){break;}
		for(int i=0;i<n;i++){
			S="";
			while(S==""){
				getline(cin,S);
			}
			S+=" ";string T;
			for(int i=0;i<S.size();i++){
				if(S[i]==' '){vec.push_back(T);T="";}
				else{T+=S[i];}
			}
		}
		char c;cin>>c;sort(vec.begin(),vec.end());
		if(vec[0][0]==c)w.push_back(make_pair(-1,vec[0]));
		for(int i=1;i<vec.size();i++){
			if(vec[i][0]==c){
				if(vec[i]==vec[i-1]){vec[vec.size()-1].first--;}
				else{vec.push_back(make_pair(-1,vec[i]));}
			}
		}
		sort(w.begin(),w.end());
		if(w.size()==0){cout<<"NA";}
		else{
			for(int i=0;i<w.size();i++){
				if(i>=5){break;}
				if(i){cout<<' ';}
				cout<<w[i].second;
			}
		}
		cout<<endl;
	}
}