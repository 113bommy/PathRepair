s=list(input())
n=len(s)-1
ans=0
while s[n]!='1' :
    ans+=1
    n-=1

if n==0:
    print(ans)
    exit()
counter=0
while n>=0 :
    if s[n]!='0' :
        counter+=1
        n-=1
        continue
    ans+=(counter+1)
    s[n]='1'
    counter=0
ans+=counter+1

print(ans)


