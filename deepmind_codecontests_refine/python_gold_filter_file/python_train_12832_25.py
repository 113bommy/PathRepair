t=int(input())

for _ in range(t):
    n=int(input())
    w=list(map(int,input().split()))
    k=0
    
    for s in range(2,102):
        f=[0]*104
        k_now=0
        for i in range(n):
            if w[i]>=s:
                continue
            
            r=s-w[i]
            if f[r]!=0:
                k_now+=1
                f[r]-=1
            else:
                f[w[i]]+=1
        k=max(k,k_now)
        
    print(k)