n,z=(int(i) for i in input().split())
k=0
x=sorted([int(i) for i in input().split()]) 
i,j=0,n//2
while i<n//2 and j<n:
    if x[j]-x[i]>=z:
        i+=1
        k+=1
    j+=1
print(k)
 