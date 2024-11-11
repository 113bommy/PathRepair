t = int(input())
while t > 0:
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    map1 = dict()
    i = 0
    while i < len(a):
        map1[str(a[i])] = i
        i += 1
    check = set()
    j = 0
    sum = 0
    for present in b:
        #print(check)
        if present not in check:
            #print('For number = ', present, ' With Index = ', map1[str(present)] - j)
            sum = sum + (2 * (map1[str(present)] - j)) + 1
            i = map1[str(present)] - 1
            while i >= 0 and not (a[i] in check):
                check.add(a[i])
                i -= 1
            j += 1
        else:
            check.remove(present)
            sum += 1
            j += 1
    print(sum)
    t -= 1