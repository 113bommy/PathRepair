n,a,b,c=map(int,input().split())
ans=0
for x in range(min(c,n//2)+1):
    for y in range(min(b,n-x*2)+1):
        if n-x*2-y>=0 and a*0.5 >=n-x*2-y: ans+=1
print(ans)    
               
