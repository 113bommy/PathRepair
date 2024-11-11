n = int(input())
a = list(map(int,input().split()))
a.sort()
res=sum(a)-len(a)
for i in range(2,10**9+1):
    s,p=0,1
    for v in a:
        s+=abs(v-p)
        if s>res: break
        p*=i
    if s>res: break
    res=s
print(res)
    
        
        
        
        