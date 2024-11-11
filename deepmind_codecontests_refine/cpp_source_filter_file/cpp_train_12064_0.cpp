#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n
    long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        long long int a;
        cin>>a;
        sum+=a;
    }
    cout<<sum/n<<endl;
    return 0;
}