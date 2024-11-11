n = int(input())
arr = sorted(map(int, input().split()))
arr1 = arr[:n]
arr2 = arr[n:]
if arr1[-1] >= arr2[0]:
    print("NO")
else:
    print("YES")