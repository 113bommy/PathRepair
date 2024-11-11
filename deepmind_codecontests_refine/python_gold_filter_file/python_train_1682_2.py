from math import gcd
n,m=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
G=A[1]-A[0]
for i in range(1,n):
    G=gcd(G,A[i]-A[i-1])
for i in range(m):
    if(G%B[i]==0):
        print("YES")
        print(A[0],i+1)
        exit()
print("NO")