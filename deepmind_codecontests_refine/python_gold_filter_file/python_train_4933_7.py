n, s, t = map(int, input().split())
l = list(map(int, input().split()))
for i in range(n):
    if s == t:
        print(i)
        exit()
    s = l[s - 1]
print(-1)