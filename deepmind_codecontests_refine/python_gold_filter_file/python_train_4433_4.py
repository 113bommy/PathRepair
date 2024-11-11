n = int(input())

s = input()

a = s.count('A')
g = s.count('G')
c = s.count('C')
t = s.count('T')


if n%4!=0 or a>n//4 or g>n//4 or c>n//4 or t>n//4 : print("===")
else:
    a = n//4 - a
    g = n//4 - g
    c = n//4 - c
    t = n//4 - t


    s = list(s)
    for i in range(n):
        if s[i] == '?':
            if a:
                s[i] = 'A'
                a-=1
            elif g:
                s[i] = 'G'
                g-=1
            elif c:
                s[i] = 'C'
                c-=1
            else:
                s[i] = 'T'
                t-=1


    print(''.join(s))
