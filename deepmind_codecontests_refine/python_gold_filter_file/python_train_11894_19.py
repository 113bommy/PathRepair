for _ in range(int(input())):
    n = int(input())

    if n <= 3:
        print("-1")
        continue

    base = [3,1,4,2]
    takes = n // 4
    
    res = []
    for i in range(takes):
        if i%2 != takes%2:
            res += [x + (4*i) for x in base]
        else:
            res += [x + (4*i) for x in base[::-1]]

    if n%4 == 1:
        res.append(n)
    elif n%4 == 2:
        res.insert(-1, n)
        res.append(n-1)
    elif n%4 == 3:
        res.insert(-1, n-1)
        res.append(n-2)
        res.append(n)

    print(" ".join(map(str,res)))