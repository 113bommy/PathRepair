def Func(time):
    a , b = time.split(':')
    r = a[::-1]
    if a == '23' and int(b) > 32:
        return 60 - int(b)
    ls = [(0,0),(1,10), (2,20), (3,30), (4,40), (5,50), (10,1), (11,11),(12,21),
          (13,31), (14,41), (15,51), (20,2), (21, 12) , (22,22),(23,32)]
    l = list(map(lambda x: x[0] * 60 + x[1], ls))
    N = int(a) * 60 + int(b)
    for i in range(len(l)):
        if l[i] >= N:
            return l[i] - N
print(Func(input()))
