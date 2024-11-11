n = map(int, input().split())
k = list(n)
t1 = k[1]*k[0]+k[3]*2
t2 =k[2]*k[0]+k[4]*2
if t1<t2:
    print('First')
if t1>t2:
    print('Second')
if t1 == t2:
    print('Friendship')