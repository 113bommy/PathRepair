# C

N=int(input())
A=list(map(int,input().split()))
p=10**9+7

sumA = sum(A)

sumA_2 = sum([a**2 for a in A])

print(((sumA**2-sumA_2)//2)%p)