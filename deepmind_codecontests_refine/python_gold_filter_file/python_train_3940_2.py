N = int(input())
K = int(input())

a = 1
for i in range(N):
    a = min(2*a, a+K)
print(a)
