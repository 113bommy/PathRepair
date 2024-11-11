for _ in range(int(input())) :
    n = int(input())
    s = set()
    for i in range(n+1) :
        if i*i > n :
            break
        s.add(i*i)
    for i in range (n+1) :
        if i*i*i > n :
            break
        s.add(i*i*i)
    s.remove(0)
    print(len(s))