def check(arg):
    need = 0
    for i in range(n):
        need += max(arg * a[i] - b[i], 0)
    return need <= k


n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

left = 0
right = 10 ** 10
while left + 1 < right:
    mid = (left + right) // 2
    if check(mid):
        left = mid
    else:
        right = mid
if check(right):
    print(right)
else:
    print(left)
