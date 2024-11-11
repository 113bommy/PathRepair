n, k = map(int, input().split())
lst = list(map(int, input().split()))

mx = 1e18
index = -1
ans = -1

for i in range(len(lst)):
    if n % lst[i] < mx:
        mx = n % lst[i]
        index = i + 1
        ans = n // lst[i]

if index == -1:
    print (1, 0)
else:
    print(index, ans)