input()
*a, = map(int, input().split())
m = min(a)
print((m, -1)[any([i % m for i in a])])