l, r = map(int, input().split())
for x in range(l, r + 1):
    s = str(x)
    if len(s) == len(set(s)):
        print(s)
        exit()
print(-1)