import collections
n = int(input())
arr = list(map(int, input().split()))
if n < 3:
    print(n)
    exit()
ans = 2
c = 2
for i in range(2, n):
    if arr[i] == arr[i-2] + arr[i - 1]:
        c += 1
    else:
        c = 2
    ans = max(ans, c)
print(ans)
