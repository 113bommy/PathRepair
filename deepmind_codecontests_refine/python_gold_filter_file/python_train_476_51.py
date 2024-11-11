# coding: utf - 8

s,v1,v2,t1,t2 = input().split()

s = int(s)

v1 = int(v1)

v2 = int(v2)

t1 = int(t1)

t2 = int(t2)

q1 = (t1*2)+(s*v1)

q2 = (t2*2)+(s*v2)

if q1==q2:
    print('Friendship')
elif q1<q2:
    print('First')
elif q1>q2:
    print('Second')