n, k = map(int, input().split())
arr = [0] * n
l = 1
for i in list(map(int, input().split())):
    arr[l - 1] = [i, str(l)]
    l += 1
arr.sort()
ans = []
m = 10 ** 5
for i in range(k):
    if arr[-1][0] - arr[0][0] <= 1 or arr[-1][0] - arr[0][0] > m:
        break
    m = arr[-1][0] - arr[0][0]
    arr[0][0] += 1
    arr[-1][0] -= 1    
    ans.append(arr[-1][1] + ' ' + arr[0][1])
    if arr[0][0] > arr[1][0]:
        j = 1
        while j < n and arr[0][0] > arr[j][0]:
            j += 1
        arr[0], arr[j - 1] = arr[j - 1], arr[0]
    if arr[-1][0] < arr[-2][0]:
        j = -2
        while  j >= -n and arr[-1][0] < arr[j][0]:
            j -= 1
        arr[-1], arr[j + 1] = arr[j + 1], arr[-1]
else:
    i += 1
print(abs(arr[-1][0] - arr[0][0]), i)
if len(ans) != 0:
    print(*ans, sep = '\n')