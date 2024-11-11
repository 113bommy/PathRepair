t = int(input())
for i in range(t):
    n, c0, c1, h = input().split()
    n, c0, c1, h = int(n), int(c0), int(c1), int(h)
    s = input()
    su = 0
    for i in s:
        if int(i) == 1:
            if c1 < c0 + h:
                su += c1
            else:
                su += c0 + h 
        elif int(i) == 0:
            if c0 < c1 + h:
                su += c0
            else:
                su += c1 + h 
    print(su)