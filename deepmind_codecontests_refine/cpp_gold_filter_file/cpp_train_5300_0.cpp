#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    while(true){
        string Red,Green,Out;
        // cin>>Red;
        getline(cin,Red);
        if(Red[0]=='-') return 0;
        // cin>>Green>>Out;
        getline(cin,Green);
        getline(cin,Out);
        if(!Out.size()){
            cout<<Green<<endl;
            continue;
        }
        // cout<<Red<<' '<<Green<<' '<<Out<<endl;
        queue<char> R,G,O;
        for(auto c:Red) R.push(c);
        for(auto c:Green) G.push(c);
        for(auto c:Out) O.push(c);

        char centre = G.front(); G.pop();
        int cnt = Green.size();
        while(true){
            // cout<<'?'<<centre<<' '<<O.front()<<endl;
            if(!O.empty()&&centre==O.front()){
                centre=R.front(); R.pop();
                O.pop();
            }else{
                cout<<centre;
                cnt--;
                if(!cnt){
                    cout<<endl;
                    break;   
                }
                centre=G.front(); G.pop();                    
            }
        }
    }

    return 0;
}