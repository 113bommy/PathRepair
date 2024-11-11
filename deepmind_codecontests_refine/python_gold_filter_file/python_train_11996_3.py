n,m = map(int,input().split())

a=[0]*5001 
for i in range(1,5001):
    a[i]=(i-1)//2 
# print(a[:20])
for i in range(1,5001):
    a[i]=a[i]+a[i-1]
# print(a[:20])
ans=[]
if m==0:
    # ans.append(1)
    aa=1
    for i in range(n):
        ans.append(aa)
        aa=aa+4
    print(*ans)
        
        
elif m>a[n]:
    print(-1)
else:
    if m in a:
        ind = a.index(m)
        for i in range(1,ind+1):
            ans.append(i)
    else:
        for i in range(1,5000):
            if a[i]<m<a[i+1]:
                for j in range(1,i+1):
                    ans.append(j)
                gap = m-a[i]
                # print(gap,i)
                ans.append(2*i-2*gap+1)
    l=len(ans)
    if l<n :
        aa = ans[l-1]
        x=aa+1
        for k in range(n-l):
            ans.append(aa+x)
            aa = aa+x
    # print(len(ans))    
    print(*ans)

                
                
                
        
        
        
        
    
