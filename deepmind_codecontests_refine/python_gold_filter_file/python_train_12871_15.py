def sieve(n): 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
prime = [True for i in range(100003+1)] 
sieve(100003)
prime[1]=False
n,m = map(int,input().split())
c=0
ans=[]
for i in range(n-2):
    ans.append([i+1,i+2,1])
    c+=1 
c+=1       
while prime[c]==False:
    c+=1
#print(c)       
ans.append([n-1,n,c-n+2])
aa=1
k=3    
for i in range(n-1,m):
    ans.append([aa,k,1000000])
    k+=1
    if k==n+1:
        aa+=1
        k=aa+2   
print(c,c)    
for i in ans:
    print(*i)    
