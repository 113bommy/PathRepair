for case in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]

    x = min(arr)

    arr.remove(x)

    for i in range(n//2):
        print(arr[i], x)