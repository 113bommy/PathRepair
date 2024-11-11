def minus(f):
    k = ""
    for i in range(len(f)-2):
        if i  <= (len(f)-2)//2:
            k+='1'
        else:
            k+='0'
 
    return k





a = int(input())

t = ""
h = str(bin (a))
for i in range(len(h)-2):
    t+=h[2+i]
if(len(t) % 2 == 0):
    kek = len(t) // 2
    tr = len(t) -1
else:
    kek = len(t) // 2 + 1
    tr = len(t)
e = ""
for i in range(tr):
    if i <= tr // 2:
        e+='1'
    else:
        e+='0'

r = 0
for i in range(kek):
    if a % int(e,2) == 0 and r == 0:
        print(int(e,2))
        r = 1

    else:
        if r == 0:
            e = minus(e)

