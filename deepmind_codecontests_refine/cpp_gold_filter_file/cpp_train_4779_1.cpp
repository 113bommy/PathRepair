#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct person{
    long long start;
    long long end;
    long long way;
    bool finished;
};
person person[100005];
long long n,t,q,key[1005];
int main(){
    //cout<<endl;
    cin>>n>>t>>q;
    priority_queue<long long> crash;
    crash.push(-9000000000000000000);
    for(int i=1; i<=n; i++) {cin>>person[i].start>>person[i].way; person[i].finished=false;}
    for(int i=1; i<=n; i++){
        if(i==1&&person[i].way==2) {person[i].end=person[i].start-t; person[i].finished=true; continue;}
        if(person[i].way==2){
            if(person[i-1].way==1){
                if((person[i].start-person[i-1].start)/2>t) {
                    person[i].end=person[i].start-t;
                    person[i-1].end=person[i-1].start+t;
                }else{
                    person[i].end=(person[i].start+person[i-1].start)/2;
                    person[i-1].end=(person[i].start+person[i-1].start)/2;
                    crash.pop();
                    crash.push((person[i].start+person[i-1].start)/2);
                    for(int j=1; j<i-1; j++){
                        if(person[j].finished!=true&&person[j].way==1) {
                            if(person[j].start+t>=crash.top()){person[j].end=crash.top(); person[j].finished=true;}
                            else person[j].end=person[j].start+t; person[j].finished=true;
                        }
                    }
                }
                person[i].finished=true;
                person[i-1].finished=true;
                continue;
            }else if(person[i].start-t<=crash.top()) {person[i].end=crash.top(); person[i].finished=true; continue;
            }else {
                person[i].end=person[i].start-t;
                person[i].finished=true;
            }}
    }
    for(int i=1; i<=n; i++){
        if(person[i].finished!=true){
            if(person[i].way==1) {person[i].end=person[i].start+t; person[i].finished=true;}
            else {person[i].end=person[i].start-t; person[i].finished=true;}
        }
    }
    //for(int i=1; i<=n; i++) cout<<"person["<<i<<"].end=="<<person[i].end<<endl;
    for(int i=1; i<=q; i++) {
        cin>>key[i];
        cout<<person[key[i]].end<<endl;
    }
}