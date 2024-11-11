l, r = map(int, input().split())
for i in range(l, r+1):
    a = list(map(str, str(i)))
    if len(set(a)) == len(a):
        print(i)
        exit()
print(-1)
        