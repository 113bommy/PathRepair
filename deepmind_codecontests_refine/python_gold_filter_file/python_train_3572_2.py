t = int(input())

for i in range(t):
    n = int(input())
    res = []
    s = []
    for i in range(n):
        res.append(input())
        if '*' in res[i]:
            s.append( (i, res[i].find('*')  ))
            if res[i].count('*') > 1: 
                s.append( ( i, res[i].rfind('*')  ))
    
    if s[0][0] == s[1][0]:
        y = n-1 if n-1 != s[0][0] else n-2
        s.append( (y, s[0][1] ) )
        s.append( (y, s[1][1] ) )
    elif s[0][1] == s[1][1]:
        x = n-1 if n-1 != s[0][1] else n-2
        s.append( (s[0][0], x ) )
        s.append( (s[1][0], x ) )
    else:
        s.append( (s[1][0],  s[0][1]) )
        s.append( (s[0][0],  s[1][1]) )
    
    s.sort()

    for i in range(n):
        if i == s[0][0]:
            print( '.'*s[0][1] + '*' + '.'*(s[1][1]-1-s[0][1]) + '*' + '.'*(n - s[1][1]-1 ) )
        elif i==s[2][0]:
            print( '.'*s[2][1] + '*' + '.'*(s[3][1]-1-s[2][1]) + '*' + '.'*(n - s[3][1]-1 ) )
        else:
            print('.'*n)
