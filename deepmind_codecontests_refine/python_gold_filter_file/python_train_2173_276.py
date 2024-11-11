n, l = map(int, input().split())
s = sorted(input() for _ in range(n))
print(*s, sep='')
