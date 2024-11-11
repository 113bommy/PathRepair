k,n=map(int,input().split())
for i in range(n):
    if k%10==0:
        k=k//10
    else:
        k=k-1
print(k)
    
