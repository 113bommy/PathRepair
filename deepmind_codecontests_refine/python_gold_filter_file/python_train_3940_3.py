N = int(input())
K = int(input())
i = 1
for _ in range(N):
    i = min(2*i,i+K)
print(i)
