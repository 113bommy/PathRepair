n,k = map(int,input().split())
ALL = 'abcdefghijklmnopqrstuvwxyz'
if k == 26:
    ll = ALL[:]
else:
    ll = ALL[0:k]
po = ''
while n>0:
    for i in ll:
        if n == 0:
            break
        else:
            po = po + i
            n -=1
print(po)