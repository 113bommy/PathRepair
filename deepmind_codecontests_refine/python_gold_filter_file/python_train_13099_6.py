n=int(input())
A=[int(i) for i in input().split()]
dp=1

for i in range(n):
    now=A[i]
    dp=dp|(dp<<now)

for i in range((sum(A)+1)//2,sum(A)+1):
    if dp&(1<<i)>0:
        print(i)
        break