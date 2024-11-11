#320A
n = list(input())
flag = True
res = True
i = 0
while i < len(n) and res:
    j = i
    if len(n[i:len(n)]) >= 3:
        if n[i:i+3] == ['1','4','4']:
            j += 3
        elif n[i:i+2] == ['1','4'] and i == j:
            j += 2
        elif n[i:i+1] == ['1'] and i == j:
            j += 1
        else:
            res = False
    elif len(n[i:len(n)]) <= 2:
        if n[i:len(n)] == ['1','4']:
            j += 2
        elif n[i:i+1] == ['1'] and i == j:
            j += 1
        else:
            res = False
    i = j
if res:
    print('YES')
else:
    print('NO')
            
        
    