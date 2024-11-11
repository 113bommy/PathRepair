n=int(input())
status=[None]*n
s=input()
for i in range(n):
    status[i]=[0]*10000
    a,b=map(int,input().split())
    if(s[i]=='0'):
        status[i][0]=0
    else:
        status[i][0]=1
    for j in range(1,10000):
        if j>=b and (j-b)%a==0:
            status[i][j]=status[i][j-1]^1
        else:
            status[i][j]=status[i][j-1]
ans=0
for i in range(10000):
    curr=0
    for j in range(n):
        curr+=status[j][i]
    ans=max(ans,curr)
print(ans)