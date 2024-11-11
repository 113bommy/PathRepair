n = int(input())
arr = list(map(int, input().split()))
arr.sort(reverse=True)
arr2 = [arr[0]]
for i in range(1, n):
    if arr[i] < arr2[-1]:
        arr2.append(arr[i])
    elif arr[i] < arr2[0]:
        arr2.insert(0, arr[i])
print(len(arr2))
print(*arr2)