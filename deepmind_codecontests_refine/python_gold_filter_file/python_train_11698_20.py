s1,r1=0,0
s2,r2=0,0
for _ in range(int(input())):
    t,s,l=map(int,input().split())
    if t==1:
        s1+=10
        r1+=s
    else:
        s2+=10
        r2+=s
if 2*r1>=s1:
    print('LIVE')
else:
    print('DEAD')
if 2*r2>=s2:
    print('LIVE')
else:
    print('DEAD')
