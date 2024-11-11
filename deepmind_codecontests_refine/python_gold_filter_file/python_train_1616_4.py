notgreat = '1'
zeroscounter = 0
flag = True
n = int(input())
a = list(map(str, input().split()))
fleg = True
for i in range(n):
    if a[i] == '0':
        print('0')
        fleg = False
        break
    if flag:
        if a[i] != '1'+'0'*(len(a[i])-1):
            notgreat = a[i]
            flag = False
        else:
            zeroscounter += len(a[i])-1
    else:
            zeroscounter += len(a[i])-1
            
if fleg:
    print(notgreat+'0'*zeroscounter)
