#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<sstream>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
#define pb push_back


class Input{
	public:
	bool isObject;
	int space;
	string key;
	string data;
	
	Input(string str){
		int nspace = 0;
		for(;;nspace++)if(str[nspace]!=' ')break;
		
		int colon = nspace;
		for(;;colon++)if(str[colon-1]==':')break;
		
		int lspace =  colon+1;
		
		space = nspace;
		key = str.substr(nspace, colon-nspace-1);
		
		if(lspace+1 < str.size()){
			data = str.substr(lspace, str.size()-lspace);
			isObject = false;
		}else{
			isObject = true;
		}
	}
	
	void print(){
		cout<<"sp = "<<space<<" key="<<key<<" data="<<data<<endl;
	}
};


string query;
vector<Input> in;


bool input(){
	getline(cin, query);
	while(!cin.eof()){
		string s;
		getline(cin, s);
		if(s=="")break;
		in.pb(Input(s));
	}
	return true;
}

class Data{
	public:
	bool isprop;
	string prop;
	string key;
	vector<Data> data;
	
	Data(string key){
		isprop = false;
		this->key = key;
	}
	Data(string key, string prop){
		isprop = true;
		this->key = key;
		this->prop = prop;
	}
	
	void print(int index){
		string space = "";
		rep(i,index)space += ' ';
		
		cout<<space; puts("----------------------");
		cout<<space; cout<<"key    : '"<<key<<"'"<<endl;
		cout<<space; cout<<"isprop : "<<isprop<<endl;
		cout<<space; cout<<"prop   : '"<<prop<<"'"<<endl;
		rep(i,data.size()){
			data[i].print(index+2);
		}
	}
};


Data kaiseki(int st, int en){
	
	//printf("st=%d  en=%d\n",st,en);
	if(st+1==en){
		return Data(in[st].key,  in[st].data);
	}
	
	
	Data ret(in[st].key);
	int head = st+1;
	int stspace = in[st+1].space;
	reps(i,st+2, en+1){
		if(i==en || in[i].space==stspace){
			ret.data.pb(kaiseki(head, i));
			head = i;
		}
	}
	return ret;
}


string calc(Data& data, string& q){
	
	
	if(q==""){
		if(data.isprop){
			stringstream sst;
			return "string \""+data.prop+"\"";
		}
		return "object";
	}
	
	int en = 1;
	for(;en<q.size();en++){
		if(q[en]=='.')break;
	}
	string key = q.substr(1, en-1);
	string nq = q.substr(en, q.size()-(en));
	
	//cout<<"q:"<<q<<"   nq:"<<nq<<"   key:"<<key<<endl;
	rep(i,data.data.size()){
		if(data.data[i].key==key){
			return calc(data.data[i], nq);
		}
	}
	
	return "no such property";
}


void solve(){
	Data parent("parent");
	
	int head = 0;
	reps(i,1,in.size()+1){
		if(i==in.size() || in[i].space==0){
			parent.data.pb(kaiseki(head, i));
			head=i;
		}
	}
	string ans = calc(parent, query);
	cout<<ans<<endl;
}

int main(){
	input();
	solve();
}