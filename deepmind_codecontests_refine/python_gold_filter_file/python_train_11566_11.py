n = int(input())
sts, sc, lst = [], 0, 0
for n in map(int, input().split()):
    if lst >= n:
        sts.append(lst)
        sc += 1
    lst = n
print(sc+1)
print(" ".join(map(str,sts+[lst])))

    
