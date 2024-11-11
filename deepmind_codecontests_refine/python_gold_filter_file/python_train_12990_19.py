
a, b, n = map(int, input().split())
i = min(n, b-1)
print((a*i)//b - a*(i//b))
