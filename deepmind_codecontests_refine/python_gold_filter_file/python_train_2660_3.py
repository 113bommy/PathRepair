a,b,c,d=map(int,input().split())
l=[a,b,c,d]
l.sort()
if l[2]<l[0]+l[1]:
    print('TRIANGLE')
    exit()
if l[3]<l[0]+l[1]:
    print('TRIANGLE')
    exit()
if l[3]<l[2]+l[1]:
    print('TRIANGLE')
    exit()
if l[3]<l[0]+l[2]:
    print('TRIANGLE')
    exit()
if l[3]==l[1]+l[2] or l[3]==l[0]+l[1] or l[2]==l[1]+l[0] or l[3]==l[0]+l[2]:
    print('SEGMENT')
    exit()
print('IMPOSSIBLE')