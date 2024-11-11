n,m=map(int,input().split())
b=[0]*m 
sum=0
s=list(map(int,input().split()))
for i in range(n):
    b[s[i]-1]+=1 
#print(b)    
for i in range(1,m):
    for j in range(0,i):
        sum+=b[j]*b[i] 
print(sum)        
   
    
    