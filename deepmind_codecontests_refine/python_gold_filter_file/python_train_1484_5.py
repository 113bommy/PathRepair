def sieve(n): 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
prime = [True for i in range(200000+1)] 
sieve(200000)
pri=[]
#pp=[10000]*(200002)
pp=[[20,20] for i in range(200001)]
for i in range(2,200001):
    if prime[i]:
        pri.append(i)
n = int(input())
lis = sorted(map(int,input().split()))
#print(pri[-1])
for i in range(len(pri)):
    aa=pri[i]
    for j in range(n):
        c=0
        at=lis[j]
        while at%aa==0:
            at=at//aa           
            c+=1
#        print(c,aa,lis[j])
        if c<pp[aa][0]:   
            pp[aa][1]=pp[aa][0]
            pp[aa][0]=c
        elif c<pp[aa][1]:
            pp[aa][1]=c
        if pp[aa][1]==0:
            break    
ans=1
#print(*pp[1:10])
#for i in range(100):
#    print(pp[pri[i]][1])           
for i in range(17984):
    ans*=(pri[i]**pp[pri[i]][1])
print(ans)                


            
           



