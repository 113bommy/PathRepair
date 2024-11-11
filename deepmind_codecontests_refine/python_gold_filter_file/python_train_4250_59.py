A,B,K=map(int,input().split())
a=0
C=[]
for i in range(1,min(A,B)+1):
    if A%i==0 and B%i==0:
        C.append(i)
print(C[-K])