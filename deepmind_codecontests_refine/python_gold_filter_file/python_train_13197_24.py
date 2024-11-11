N = int(input())
A=list(map(int,input().split()))
A.sort(reverse=True)
sum=0
for i in range(1,N):
    sum+=A[i//2]
print(sum)