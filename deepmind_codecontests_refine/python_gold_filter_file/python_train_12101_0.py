t = int(input())

for e in range(t):
    n, k = [int(x) for x in input().split()]
    
    s = ["a"] * n
    cont = 0
    aux = 0
    while True:
        if aux > k:
            aux -= cont
            break
        
        cont += 1
        aux += cont

    tmp = k - aux
    if tmp > 0:
        pos1 = n - 1 - cont
        pos2 = n - tmp
        
    else:
        cont -= 1
        pos1 = n - 1 - cont
        pos2 = pos1 + 1
    
    s[pos1] = "b"
    s[pos2] = "b"
    
    for e in s:
        print(e, end="")
    print()
