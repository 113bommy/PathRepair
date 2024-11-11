#include <bits/stdc++.h>
using namespace std;

int main(){
int a,b,c;
cin>>a>>b>>c;
if (a<c && c<b){
cout << "Yes";
}else if(b<c && c<a){
cout<< "Yes";
}else{
cout << "No";
}

}
