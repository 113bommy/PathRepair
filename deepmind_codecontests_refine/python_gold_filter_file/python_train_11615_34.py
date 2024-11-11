def fn1():
    # 1-12 hours
    # 00-60 minutes
    time = list(input())

    if int(time[0]) > 1:
        if int(time[1]) < 2: time[0] = '1'
        else: time[0] = '0'
    if time[0]!='0':
        if int(time[1])>2: time[1]='1'
    
    if int(time[3])>=6: time[3]='5'
    if time[0] == time[1] == '0': time[1]='1'
    print(''.join(time))
    return


def fn2():
    # 1-24 hours
    # 00-60 minutes
    time = list(input())

    if int(time[0]) > 2: time[0] = '0'
    if int(time[0])>=2:
        if int(time[1])>=4: time[1]='3'

    if int(time[3])>=6: time[3]='5'
    
    print(''.join(time))
    return
    
    

f = int(input())
if f == 12: fn1()
else: fn2()
