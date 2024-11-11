n, m = [int(i) for i in input().split()]
a = [[int(j) for j in input().split()] for i in range(n)]
b = [int(input()) for i in range(m)]

ans = [sum([a[j][i] * b[i] for i in range(m)]) for j in range(n)]
print(*ans, sep='\n')
