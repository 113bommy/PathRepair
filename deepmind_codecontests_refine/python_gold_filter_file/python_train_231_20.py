t = int(input())
for i in range(t):
    n = int(input())
    isone = False
    m = 0
    while n > 1:
        if n%6 == 0:
            n = n/6
        elif n%3 == 0:
            n = n*2
        else:
            break
        m+=1
    if n == 1:
        print(m)
    else:
        print(-1)