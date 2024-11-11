n,m = map(int,input().split())
print(max(0,n-2*m),end=" ")
 
k = 0
while k*(k-1)//2<m:
    k+=1
print(n-k)