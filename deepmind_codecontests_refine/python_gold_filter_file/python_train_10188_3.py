N = int(input())
P = [int(x) for x in input().split()]

a = [i*N + 1 for i in range(N)]
b = [i*N + 1 for i in reversed(range(N))]

for i in range(N) :
    a[P[i]-1] += i

print(*a)
print(*b)
