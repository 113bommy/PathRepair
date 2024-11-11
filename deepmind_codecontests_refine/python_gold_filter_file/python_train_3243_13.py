n,B,A = map(int,input().split())
s = input().split()
b,a = B,A
complete = True
for i,si in enumerate(s):
    if b==0 and a==0:
        print(i)
        complete = False
    if si == '0':
        if a>0:
            a-=1
        else:
            b -= 1
    if si == '1':
        if (a==A and a>0) or (b==0) :#if acc full
            a-=1
        elif b>0: #chargable
            a += 1
            b -= 1
if complete:
    print(n)