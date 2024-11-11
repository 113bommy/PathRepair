n, k = map(int, input().split())

arr = list(map(int, input().split()))

mx = 0

for i in range(n - k + 1):
    sm = sum(arr[i:i + k])
    mx = max(mx, sm / k)
    for j in range(i + k, n):
        sm += arr[j]
        mx = max(mx, sm / (j - i + 1))

print(mx)
