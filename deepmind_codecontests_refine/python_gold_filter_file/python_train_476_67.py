s, v1, v2, t1, t2 = map(int, input().split())
a = t1 + s * v1 + t1
b = t2 + s * v2 + t2
if a == b:
    print('Friendship')
else:
    if a < b:
        print('First')
    else:
        print('Second')
