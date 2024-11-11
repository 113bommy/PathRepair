N = int(input())
K = int(input())
z = 1
for _ in range(N):
    z = min(z*2, z+K)
print(z)