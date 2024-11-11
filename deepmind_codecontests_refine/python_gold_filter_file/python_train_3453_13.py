n = int(input())
arr = sorted(list(map(int, input().split())))
flag, cz = False, arr.count(0)
p = 0
for i in range(2, n):
    if arr[i] == arr[i-1] and arr[i-1] == arr[i-2]:
        flag = True
for i in range(1, n):
    if arr[i] == arr[i-1]:
        p += 1
        if i - 2 >= 0 and arr[i-2] == arr[i-1] - 1:
            flag = True
s = sum(arr)
if (s - (n * (n - 1) // 2)) % 2 == 0 or flag or cz >= 2 or p >= 2:
    print("cslnb")
else:
    print("sjfnb")
