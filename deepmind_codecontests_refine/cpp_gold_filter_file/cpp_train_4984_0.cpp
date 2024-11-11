#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	int a[] = {1,3,5,7,9,11,15,17,19,21,23,25};
	cin >>n;
	cin.ignore();
	while(n--){
		string word;
		getline(cin,word);
		for(int i=0; i<12; i++){
			for(int j=0; j<26; j++){
				string affine = word;
				for(int k=0; k<(int)word.size(); k++){
					if(affine[k]>='a' && affine[k]<='z'){affine[k] = (a[i]*(affine[k]-'a')+j)%26+'a';}
				}
				if(affine.find("this")+1 || affine.find("that")+1){
					cout<<affine<<endl;
					goto label;
				}
			}
		}
		label:;
	}
	return 0;
}