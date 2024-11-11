n,k = map(int,input().split())
a = list(map(int,input().split()))
b = sorted(a)
if sum(b) <= k:
    print(len(a))
    for i in range(len(a)):
        print(i+1,end = " ")
else:
    if b[0] > k:
        print(0)
    else:
        c = []; p = 0; d = []
        for i in range(len(b)):
            if p + b[i] <= k:
                for j in range(len(a)):
                    if a[j] == b[i] and not j in d:
                        c.append(j+1)
                        p += b[i]
                        d.append(j)
                        break
            else:
                break
        print(len(c))
        print(*c)