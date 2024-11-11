def divide_2(a, m):
    r = 0
    q = []
    for x in a:
        cur = r * m + x
        q.append(cur // 2)
        r   = cur % 2
    return q

def add(s, t, m):
    r = 0
    a = []
    
    for x, y  in zip(s[::-1], t[::-1]):
        cur = r+x+y
        a.append(cur % m )
        r   = cur // m
        
    if r != 0:    
        a.append(r)    
        
    return a[::-1]

def to_num(s):
    a = []
    for x in s:
        a.append(ord(x)-ord('a'))
    return a

def to_char(s, k):
    a = []
    for x in s[-k:]:
        a.append(chr(x+ord('a')))
    return ''.join(a)

k = int(input())
x = to_num(input())
y = to_num(input())

print(to_char(divide_2(add(x, y, 26), 26), k))