N=int(input())
s=0
A=list(map(int,input().split()))
li=[0]*(2*(10**5)+1)
for i in range(N):
    li[A[i]]+=1
for j in range(N+1):
    s+=li[j]*(li[j]-1)//2
for k in range(N):
    print(s-li[A[k]]+1)
