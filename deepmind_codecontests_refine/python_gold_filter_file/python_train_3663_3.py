n = int(input())
arr = list(map(lambda x: int(x), input().split(' ')))

for i in range(0, n):
    arr[i] = arr[i], i

arr.sort(reverse=True)

cc = 0

for i in range(0, n):
    cc += arr[i][0] * i + 1

print(cc)

for i in range(0, n):
    print(arr[i][1] + 1, end=' ')

print()
