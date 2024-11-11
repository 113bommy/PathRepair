n = int(input())
arr = [int(i) for i in input().split()]
arr.sort()
m = arr[0]
flag = 1
for i in range(1,n):
    if arr[i] % m != 0:
        print(-1)
        flag = 0
        break
if flag:
    print(m)