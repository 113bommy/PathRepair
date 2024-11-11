t = int(input())

while t>0:
    n = input()
    d = {'A':0 , 'B': 0 , 'C': 0}
    for i in n:
        if i in d:
            d[i] += 1
        else:
            d[i] = 0
        
    if d['A']+d['C']==d['B']:
        print('YES')
    else:
        print('NO')
    
    t-=1