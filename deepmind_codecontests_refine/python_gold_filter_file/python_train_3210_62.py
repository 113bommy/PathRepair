A,B,K=map(int,input().split())
b=min(A+K-1,B)
for i in range(A,b+1):
    print(i)
b2=max(b+1,B-K+1)
for i in range(b2,B+1):
    print(i)