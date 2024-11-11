n,t=list(map(int,input().split()))
l=list(map(int,input().split()))
ans=0
j=0
for i in range(n):
    ans+=l[i]
    #print(ans)
    if ans>t:
        ans-=l[j]
        j+=1
print(i-j+1)