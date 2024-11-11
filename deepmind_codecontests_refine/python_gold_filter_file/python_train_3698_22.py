input(); s = input()
t = set(s)
if (len(t) == 1):
    print(s[0])
elif len(t) == 3:
    print("BGR")
else:
    a, b = t
    x, y = s.count(a), s.count(b)
    if x == 1 and y == 1:
        print('BGR'.strip(a+b))
    elif x==1 and y > 1:
        for i in "BGR": 
            if i != b: print(i, end = "")
    elif x>1 and y == 1:
        for i in "BGR": 
            if i != a: print(i, end = "")
    else:
        print('BGR')