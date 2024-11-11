n = int(input())

def valid(s):
    m = len(s)
    lower = []
    upper = [] 
    digit = []
    for i in range(m):
        if ord(s[i]) <= 57:
            digit.append(i)
        elif ord(s[i]) <= 90:
            upper.append(i)
        else:
            lower.append(i)
    
    d = len(digit)
    u = len(upper)
    l = len(lower)
    if d > 0 and u > 0 and l > 0:
        return s

    if d == m:
        s[0] = 'A'
        s[1] = 'a'
        return s

    if u == m:
        s[0] = '1'
        s[1] = 'a'
        return s

    if l == m:
        s[0] = '1'
        s[1] = 'A'
        return s

    if d + u  == m:
        if d > u:
            s[digit[0]] = 'a'
        else:
            s[upper[0]] = 'a'
        return s

    if d + l  == m:
        if d > l:
            s[digit[0]] = 'A'
        else:
            s[lower[0]] = 'A'
        return s

    if u + l  == m:
        if l > u:
            s[lower[0]] = '1'
        else:
            s[upper[0]] = '1'
        return s
    
    
for i in range(n):
    s = list(input())
    res = valid(s)
    print(''.join(res))
