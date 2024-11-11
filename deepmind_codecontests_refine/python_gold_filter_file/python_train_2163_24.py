N = int(input())
A = list(map(int,input().split()))
sumA = sum(A)
c = 0
for a in A:
  c += a**2
print(((sumA**2 - c)//2) % (10**9+7))