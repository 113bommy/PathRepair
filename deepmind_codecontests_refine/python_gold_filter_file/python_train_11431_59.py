n, m = map(int, input().split())
print(*[x for x in range(m-n+1, m+n)])