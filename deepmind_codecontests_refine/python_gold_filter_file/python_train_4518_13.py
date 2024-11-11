a,b,c = map(int,input().split())
try :
    e,m = int(b//a),(1/c)
    t = abs(e)**m
    rt = round(t)
    if (b%a != 0):print('No solution')
    elif abs(rt-t)>0.0001:print('No solution')
    elif e<0 and m%2==0:print('No solution')
    else :print(int(rt) if e>0 else -1*int(rt))
except:print(1 if a == b == 0 else 'No solution')
