#include <bits/stdc++.h>
std::string s;
int main(void){
    std::cin>>s;
    return 0&(int)printf("%s",((s[0]==s[s.size()-1])^(s.length()%2))?"First\n":"Second\n\r");
}