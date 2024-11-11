def func(h, w, r, c):
    fill = 0
    
    for i in range(h):
        for j in range(w):
            if i > c[j] and j > r[i]:
                fill += 1
            if j == r[i] and i < c[j] or i == c[j] and j < r[i]:
                return(0)
    #if fill == 0:
    #    return(0)
    return((2 ** fill) % 1000000007)
        
h, w = tuple(map(int, input().split(" ")))

#print(h, w)
r = list(map(int, input().split(" ")))
c = list(map(int, input().split(" ")))

print(func(h, w, r, c))