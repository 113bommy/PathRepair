for i in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a = list(a)
    a.sort(reverse = True)
    sum = 0
    lst = []
    for i in range(n):
        if sum != a[i]:
            sum += a[i]
        else :
            lst.append(a[i])
    if sum in lst and len(set(lst)) == 1:
        print(len(lst) + 1)
    else :
        print(1)
