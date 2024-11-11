n = list(map(int, input().split()))
in_arr = [int(x) for x in input().split()]
in_arr.sort()
arr = []
for i in range(int(n[0]/2), n[0]):
    arr.append(in_arr[i])
l = 0
r = 10000000001
while r - l > 1:
    mid = int((r + l)/2)
    total = 0
    for i in arr:
        total += max(0, mid - i)
    if total <= n[1]: l = mid
    else: r = mid
print(l)