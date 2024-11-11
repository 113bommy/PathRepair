for _ in range(int(input())):
    n = int(input())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    for i in range(n):
        if arr2[i] == 0:
            for j in range(i+1, n):
                if arr2[j] != 1 and arr1[i] < arr1[j]:
                    arr1[i], arr1[j] = arr1[j], arr1[i]
    print(*arr1)