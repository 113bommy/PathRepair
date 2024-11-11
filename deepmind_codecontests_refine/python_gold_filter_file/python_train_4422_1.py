n = int(input())
alist = list(map(int, input().split()))

if alist == sorted(alist):
    print(0)
    exit()

ans = []
for i in range(n):
    mi = min(alist[i:])
    ind = i + alist[i:].index(mi)
    ans.append([i, ind])
    alist[i], alist[ind] = alist[ind], alist[i]

print(len(ans))
for tup in ans:
    print(*tup)


    