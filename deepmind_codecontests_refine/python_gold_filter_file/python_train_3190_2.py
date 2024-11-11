a1 = input()
a2 = input()
a3 = input()
f=input()
b4 = input()
b5 = input()
b6 = input()
g=input()
c7 = input()
c8 = input()
c9 = input()
x,y=list(map(int,input().split()))
g=x % 3
h=y % 3
if g == 1:
    if h == 1:
        if '.' in a1[0:3] or '.' in a2[0:3] or '.' in a3[0:3]:
            a1 = a1[0:3].replace('.', '!')+a1[3:]
            a2 = a2[0:3].replace('.', '!')+a2[3:]
            a3 = a3[0:3].replace('.', '!')+a3[3:]
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
    if h==2:
        if '.' in a1[4:7] or '.' in a2[4:7] or '.' in a3[4:7]:
            a1 = a1[:4]+a1[4:7].replace('.', '!')+a1[7:]
            a2 = a2[:4]+a2[4:7].replace('.', '!')+a2[7:]
            a3 = a3[:4]+a3[4:7].replace('.', '!')+a3[7:]
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
    if h==0:
        if '.' in a1[8:11] or '.' in a2[8:11] or '.' in a3[8:11]:
            a1 = a1[:8]+a1[8:11].replace('.', '!')
            a2 = a2[:8]+a2[8:11].replace('.', '!')
            a3 = a3[:8]+a3[8:11].replace('.', '!')
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
elif g==2:
    if h == 1:
        if '.' in b4[0:3] or '.' in b5[0:3] or '.' in b6[0:3]:
            b4 = b4[0:3].replace('.', '!')+b4[3:]
            b5 = b5[0:3].replace('.', '!')+b5[3:]
            b6 = b6[0:3].replace('.', '!')+b6[3:]
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
    if h == 2:
        if '.' in b4[4:7] or '.' in b5[4:7] or '.' in b6[4:7]:
            b4 = b4[:4]+b4[4:7].replace('.', '!')+b4[7:]
            b5 = b5[:4]+b5[4:7].replace('.', '!')+b5[7:]
            b6 = b6[:4]+b6[4:7].replace('.', '!')+b6[7:]
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
    if h == 0:
        if '.' in b4[8:11] or '.' in b5[8:11] or '.' in b6[8:11]:
            b4 = b4[:8]+b4[8:11].replace('.', '!')
            b5 = b5[:8]+b5[8:11].replace('.', '!')
            b6 = b6[:8]+b6[8:11].replace('.', '!')
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
elif g==0:
    if h == 1:
        if '.' in c7[0:3] or '.' in c8[0:3] or '.' in c9[0:3]:
            c7 = c7[0:3].replace('.', '!')+c7[3:]
            c8 = c8[0:3].replace('.', '!')+c8[3:]
            c9 = c9[0:3].replace('.', '!')+c9[3:]
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
    if h == 2:
        if '.' in c7[4:7] or '.' in c8[4:7] or '.' in c9[4:7]:
            c7 = c7[:4]+c7[4:7].replace('.', '!')+c7[7:]
            c8 = c8[:4]+c8[4:7].replace('.', '!')+c8[7:]
            c9 = c9[:4]+c9[4:7].replace('.', '!')+c9[7:]
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
    if h == 0:
        if '.' in c7[8:11] or '.' in c8[8:11] or '.' in c9[8:11]:
            c7 = c7[:8]+c7[8:11].replace('.', '!')
            c8 = c8[:8]+c8[8:11].replace('.', '!')
            c9 = c9[:8]+c9[8:11].replace('.', '!')
        else:
            a1 = a1.replace('.', '!')
            a2 = a2.replace('.', '!')
            a3 = a3.replace('.', '!')
            b4 = b4.replace('.', '!')
            b5 = b5.replace('.', '!')
            b6 = b6.replace('.', '!')
            c7 = c7.replace('.', '!')
            c8 = c8.replace('.', '!')
            c9 = c9.replace('.', '!')
print(a1)
print(a2)
print(a3)
print()
print(b4)
print(b5)
print(b6)
print()
print(c7)
print(c8)
print(c9)