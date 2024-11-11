def count(a):
    a = sorted(a)
    s = 0
    d = 0
    i = 2
    j = 1
    for e in a:
        s = s + abs(e-i)
        i = i+2
    

    for e in a:
        d = d + abs(e-j)
        j = j+2
    return(min(s,d))
c = input()
a = [int(x) for x in input().split()]
print(count(a))