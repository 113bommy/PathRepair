n, m = map(int, input().split())
l = []
for i in range(m):
    l += list(map(int, input().split()))
for i in range(n):
    print(l.count(i+1))