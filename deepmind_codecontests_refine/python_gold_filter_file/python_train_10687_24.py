n,k=map(int,input().split())
for _ in range(1,k+1):
       if(n%10==0):n=n/10
       elif(n%10!=0):n=n-1
print(int(n))