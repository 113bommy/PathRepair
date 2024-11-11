k,n,w=map(int,input().split())
w=w*(w+1)//2
ans=w*k-n
if(ans<=0):
    ans=0
print(ans)