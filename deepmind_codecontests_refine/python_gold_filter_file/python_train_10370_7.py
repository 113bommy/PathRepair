n, k = map(int, input().split())
arr = [int(x) for x in input().split()]
suma = 0
i = 0
v=0
while suma < k and i < n:
    if arr[i]+v < 8:
        suma += arr[i] + v
        v=0
    else:
        suma += 8
        v += arr[i]-8
    i += 1

if suma >= k:
    print(i)
else:
    print(-1)