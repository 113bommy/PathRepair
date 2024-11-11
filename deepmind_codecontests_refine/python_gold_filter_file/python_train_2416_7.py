t = int(input())

for _ in range(t):
    n = int(input())
    p = [input() for _ in range(n)]
    change = 0
    s = set()
    
    for i in range(n):
        if p[i] in s:
            for j in range(10):
                if not str(j)+p[i][1:] in p:
                    change += 1
                    p[i] = str(j)+p[i][1:]
                    break
        
        s.add(p[i])
    
    print(change)
    
    for pi in p:
        print(pi)