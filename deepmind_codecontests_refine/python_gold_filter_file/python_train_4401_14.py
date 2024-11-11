for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    curr = arr[0]
    found = False
    for i in range(1, n):
        if curr != arr[i]:
            found = True
    if found:
        print(1)
    else:
        print(n)
