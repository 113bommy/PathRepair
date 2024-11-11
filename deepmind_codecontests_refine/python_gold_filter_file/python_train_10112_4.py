n,m=map(int,input().split())
l=list(map(int,input().split()))
x=[0]*(n+1)
ans=[0]*(m+1)
for i in l:
    x[i]+=1
    ans[x[i]]+=1
    #print(x,ans)
    if ans[x[i]]==n:
        print('1',end='')
    else:
        print('0',end='')
