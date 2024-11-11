n, m = map(int, input().split())
A = [input().split() for _ in range(n)]
b = [input()for _ in range(m)]
for a in A:
    print(sum(int(x)*int(y) for x, y in zip(a,b)))
