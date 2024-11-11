n = int(input())
if n == 0:
    print(0)
else:
    tot = 0
    i = 0
    while tot < n:
        i += 1
        tot += i * (i+1)/2
        
    if tot == n:
        print(i)
    else:
        print(i-1)