p = int(input())
arr = []
for i in range(p):
    m, n = map(int, input().split())
    arr1 = [int(d) for d in input().split(" ")]
    arr2 = [int(d) for d in input().split(" ")]
    if len(arr1) >= len(arr2):
        for j in range(len(arr2)):
            if arr1.count(arr2[j]) > 0:
                arr.append(["YES", arr2[j]])
                break
            elif j == len(arr2) - 1:
                arr.append("NO")
    else:
        for t in range(len(arr1)):
            if arr2.count(arr1[t]) > 0:
                arr.append(["YES", arr1[t]])
                break
            elif t == len(arr1) - 1:
                arr.append("NO")


for j in range(len(arr)):
    if arr[j] == "NO":
        print("NO")
    else:
        print("YES")
        print(1, arr[j][1])
