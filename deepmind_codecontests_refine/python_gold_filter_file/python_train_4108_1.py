n=int(input())
L=list(map(int,input().split()))
R=[0]*100001
for i in L:
    R[i]+=i
for i in range(2,100001):
    R[i]=max(R[i-1],R[i-2]+R[i])
print(R[100000])
