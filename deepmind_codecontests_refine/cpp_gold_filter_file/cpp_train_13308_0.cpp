#include<set>
#include<cstdio>
#include<cctype>
#include<string>
inline int getint() {
    register char ch;
    while(!isdigit(ch=getchar()));
    register int x=ch^'0';
    while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
    return x;
}
int main() {
    std::multiset<std::string> set;
    for(register int i=getint();i;i--) set.insert("a");
    for(register int i=getint();i;i--) set.insert("b");
    for(register int i=getint();i;i--) set.insert("c");
    while(set.size()>1) {
        std::string s=*set.begin(),t=*set.rbegin();
        set.erase(set.lower_bound(s));
        set.erase(set.lower_bound(t));
        set.insert(s+t);
    }
    printf("%s\n",(*set.begin()).c_str());
    return 0;
} 