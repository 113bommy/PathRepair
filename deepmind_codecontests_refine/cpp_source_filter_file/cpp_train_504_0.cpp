include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n,number;
	long long a,b;
	bool flag;
	map<int,long long> info;
	vector<int> seq;
	
	while(cin >> n && n){
		info.clear();
		seq.clear();
		while(n--){
			cin >> number >> a >> b;
			if(!info[number])seq.push_back(number);
			info[number] += a*b;
		}
		flag = true;
		for(int i=0;i<seq.size();i++){
			if(info[seq[i]]>=1000000){
				flag = false;
				cout << seq[i] << endl;
			}
		}
		if(flag)cout << "NA" << endl;
	}
}