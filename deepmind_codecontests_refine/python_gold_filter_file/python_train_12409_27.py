l, r = map(int, input().split())
for i in range(l, r + 1):
    si = str(i)
    if len(si) == len(set(si)):
        print(i)
        exit()
print(-1)