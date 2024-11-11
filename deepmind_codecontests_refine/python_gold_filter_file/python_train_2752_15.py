a=int(input())
n=0
p=0
k=list(map(int,input().split()))
    
for i in range(a):    
    if k[i]!=-1:
        p=p+k[i]
    elif p>0:
        p-=1
    else:
        n+=1
    
        
print(n)
    