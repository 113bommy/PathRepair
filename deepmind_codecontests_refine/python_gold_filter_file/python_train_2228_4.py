n,m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
t = arr[n-1] - arr[0]

for i in range(m-n+1):
    if arr[i+n-1] - arr[i] < t:
        t=arr[i+n-1] - arr[i]
print(t)