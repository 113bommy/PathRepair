a, b, x = map(int, input().split())
s = []
if x % 2 == 0:
    if x == a*2:
        s.extend(['10']*(x//2))
        s.extend(['1']*(b-x//2))
        print(*s, sep='')
    else:
        s.extend(['01']*(x//2))
        s.extend(['1'] * (b - x//2))
        s.extend(['0'] * (a - x//2))
        print(*s, sep='')
else:
    if x == b*2-1:
        s.extend(['10']*((x+1)//2))
        s.extend(['0']*(a-(x+1)//2))
        print(*s, sep='')
    else:
        s.extend(['01'] * (x // 2))
        s.extend(['0'] * (a - x // 2))
        s.extend(['1'] * (b - x // 2))
        print(*s, sep='')
