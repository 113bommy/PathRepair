I = [int(x) for x in input().split()]
time1 = I[0]*I[1] + 2*I[3]
time2 = I[0]*I[2] + 2*I[4]
if time1 < time2:
    print('First')
elif time1 > time2:
    print('Second')
else:
    print('Friendship')
