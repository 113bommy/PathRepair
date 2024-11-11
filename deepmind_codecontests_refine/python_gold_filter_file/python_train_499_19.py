A,B,C,X,Y=map(int,input().split())

K=10**9
for i in range(10**5+1):
    S=i*2*C+max(0,X-i)*A+max(0,Y-i)*B
    K=min(K,S)
print(K)