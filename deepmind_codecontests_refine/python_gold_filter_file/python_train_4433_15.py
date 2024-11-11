n = int(input())
l = list(input())

a = l.count('A')
g = l.count('G')
c = l.count('C')
t = l.count('T')
q = l.count('?')
if n % 4 != 0:
    print('===')
elif max(a,g,c,t) > n/4:
    print('===')
else:
    for i in range(len(l)):
        if l[i] == '?':
            if a < n/4:
                l[i] = 'A'
                a += 1
            elif g < n/4:
                l[i] = 'G'
                g += 1
            elif c < n/4:
                l[i] = 'C'
                c += 1
            elif t < n/4:
                l[i] = 'T'
                t += 1

    print(''.join(l))
