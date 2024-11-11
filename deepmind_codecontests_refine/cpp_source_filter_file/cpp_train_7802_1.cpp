#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        char pro[1000];
        scanf(" %s",pro);
        int num,;
        num=strlen(pro);
        int a[1000]={};
        for(int i=0;pro[i]!='\0';i++){
            a[i]=pro[i]-'0';
        }
        int ans=0,count=0;
        for(int i=0;i<num;i++)ans+=a[i];
        while(ans>9){
            ans-=9;
            count++;
        }
        if((num-1+count)%2==0)printf("Audrey wins.\n");
        else printf("Fabre wins.\n");
    }
    return 0;
}