_, num = int(input()), [int(i) for i in input()]

def f(x):

    s = 0
    cnt = 0
    
    for i in num:
        s+=i
        if s>x: return False
        if s==x:
            s = 0
            cnt += 1

    return (cnt > 1) and (s==0)


for i in range(sum(num)+1):
    if f(i):
        print('YES')
        raise SystemExit

print('NO')
