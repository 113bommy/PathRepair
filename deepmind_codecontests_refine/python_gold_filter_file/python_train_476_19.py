s,v1,v2,t1,t2 = map(int,input().split())
time1 = t1+s*v1+t1
time2 = t2+s*v2+t2
#print(time1,time2)
if time2 > time1:
    print('First')
elif time2 < time1:
    print('Second')
else:
    print('Friendship')