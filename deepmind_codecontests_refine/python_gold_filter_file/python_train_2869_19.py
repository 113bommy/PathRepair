n = int(input())
l = []
for i in range(n):
    s = input()
    L = len(s)
    if L > 10:
        l.append(s[0] + str(L-2) + s[-1])
    else:
        l.append(s)
for x in l:
    print(x)
    
