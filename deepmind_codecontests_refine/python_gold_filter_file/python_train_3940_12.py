N = int(input())
K = int(input())
k = 1
for i in range(N):
    k = min(2*k,k+K)
print(k)