#include <iostreaam>
#include <string>
using namespace std;

int main(){
string in;
int a[300] = {};
cin >> in;
for(int i = 0;i<in.size();i++){
a[in[i]]++;
if(a[in[i]] > 1){
cout << "no" << endl;
return 0;
}
}
cout << "yes" << endl;
return 0;
}