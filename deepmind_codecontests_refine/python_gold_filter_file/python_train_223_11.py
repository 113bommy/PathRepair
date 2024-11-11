n = int(input())
for i in range(n):
    a, b, n = [int(r) for r in input().split()]
    f = [a, b, a ^ b]
    print(f[n%3])