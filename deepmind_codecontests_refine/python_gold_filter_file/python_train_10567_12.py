s=input()
res=[i for i in s]
m=int(input())
for _ in range(m):
    l,r,k = map(int,input().split())
    l-=1
    r-=1
    
    k=k%(r-l+1)
    n=r-l+1
    ans=[0]*n
    for i in range(l,r+1):
        if i-l<k:
            ans[i-l]=res[r-l+1-k+i]
            
        else:
            ans[i-l]=res[i-k]
            
    res[l:r+1]=ans
    
print(''.join(res))