n = int(input())
arr = [int(x) for x in input().split()]
one = zero = n-1
for i in range(n-1, 0, -1):
    if arr[i] != arr[i-1]:
        print(i)
        break
        