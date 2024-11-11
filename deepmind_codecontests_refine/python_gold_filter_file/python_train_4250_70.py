A,B,C=map(int,input().split())
T=[]
for i in range(1,min(A,B)+1):
    if A%i==0 and B%i==0:
        T.append(i)
print(T[-C])