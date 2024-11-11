import math

n, k = map(int, input().split())

arr = [int(z) for z in input().split()]

if n == k:
    print((f'{sum(arr):.6f}'))
    exit()

res = 0

if k > math.ceil(n/2):
    for i in range(n-k+1):
        res += arr[i] * (i+1)
        #print(arr[i], i+1, res)

    for i in range(n-k+1, (n-k+1) + (2*k - n) - 1):
        res += arr[i] * (n-k+1)
        #print(arr[i], n-k+1, res, 'bruh')

    for i in range((n-k+1) + (2*k - n) - 1, n):
        res += arr[i] * (n-i)
        #print(arr[i], n-i, res)
else:
    for i in range(k - 1):
        res += arr[i] * (i + 1)
        res += arr[-(i + 1)] * (i + 1)
        # print(arr[i], arr[-(i+1)], res)

    for i in range(k - 1, n - k + 1):
        res += arr[i] * (k)
        # print(arr[i], k, res, 'bruh')

print(res/(n-k+1))


