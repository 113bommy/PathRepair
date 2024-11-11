w, m, k = map(int, input().split())
cost, num = 0, 0
ln = len(str(m))
aim = 10**ln
if (aim - m)*ln*k <= w:
    cost += (aim - m)*ln*k
    num += (aim - m)
    m = aim
    ln += 1
    while True:
        if ln*k*9*10**(ln-1)+cost <= w:
            cost += ln*k*9*10**(ln-1)
            num += 9*10**(ln-1)
            m = 10**ln
            ln += 1
        else:
            break
lastm = m
aim = 10**ln
mid, lastn = 0, 0
while aim != m+1:
    mid = m + (aim-m)//2
    if ln*k*(mid-lastm)+cost <= w:

        m = mid

    else:
        aim = mid

print(num + m - lastm)