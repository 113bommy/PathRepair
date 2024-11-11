#inlcude<iostream>
int main(){int a,b;std::cin>>a>>b;std::printf("%sossible\n",(a*b%3&1)?"Imp":"P");}