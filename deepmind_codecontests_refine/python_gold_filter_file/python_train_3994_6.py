n, k = map(int, input().split())
a = list(map(int, input().split()))

diff = 0
dict = {}
end = -1
l, r = 0, 0

for i in range(n):
    if a[i] in dict:
        dict[a[i]] += 1
    else:
        dict[a[i]] = 1
        diff += 1
    if diff == k:
        end = i
        break

if end==-1:
    print('-1 -1')
else:
    for i in range(end):
        if dict[a[i]] != 1:
            dict[a[i]] -= 1
        else:
            l = i
            break
    for i in range(end, 0, -1):
        if dict[a[i]] != 1:
            dict[a[i]] -= 1
        else:
            r = i
            break
    print(l+1, r+1)
