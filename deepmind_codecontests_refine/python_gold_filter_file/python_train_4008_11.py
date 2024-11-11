[n, w] = list(map(int, input().split()))
arr = list(map(int, input().split()))

tmpArr = list(reversed(sorted(arr)))
x = min(tmpArr[n -1] / 2, tmpArr[-1])
print(min(3 * x * n, w))