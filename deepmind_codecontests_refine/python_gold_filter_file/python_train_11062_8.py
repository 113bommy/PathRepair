for _ in range(int(input())):
    p = int(input())-1
    a = list(map(int, input().split()))
    if a == sorted(a):
        print("0")
    elif a == sorted(a)[::-1]:
        print("0")
    else:
        while p >= 1 and a[p-1] >= a[p]:
            p -= 1
        while p >= 1 and a[p-1] <= a[p]:
            p -= 1
        print(len(a) - len(a[p:]))
