for _ in range(int(input())):
    n = int(input())
    lst = [int(i) for i in input().split()]
    result = 0
    for i in range(1, n):
        diff = lst[i-1]-lst[i]
        if diff > 0:
            result = max(result, len(bin(diff))-2)
            lst[i] = lst[i-1]
    print(result)
