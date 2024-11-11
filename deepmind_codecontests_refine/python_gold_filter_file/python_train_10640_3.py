def rev(l1, l2):
    m = (len(l1) - len(l2))//2
    if m==0:
        return []
    
    torev = []
    
    for k in l1:
        if k[::-1] not in l2:
            torev.append(k)
    
    if len(torev) < m:
        return -1
    else:
        return torev[:m]
    

for _ in range(int(input())):
    n = int(input())
    
    oo = []
    zz = []
    zo = set()
    oz = set()
    ind = dict()
    
    for i in range(n):
        s = input()
        ind[s] = i+1
        if s[0] == '0':
            if s[-1] == '0':
                zz.append(s)
            else:
                zo.add(s)
        else:
            if s[-1] == '0':
                oz.add(s)
            else:
                oo.append(s)

    if len(oz) >= len(zo):
        strings = rev(oz, zo)
    else:
        strings = rev(zo, oz)
    
    if strings == -1:
        print(-1)
    elif len(oo) >= 1 and len(zz) >= 1 and len(oz) + len(zo) == 0 :
        print(-1)
    else:
        print(len(strings))
        print(' '.join([str(ind[x]) for x in strings]))