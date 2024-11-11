t = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))

f_a = t[0]*a[0]
f_b = t[0]*b[0]
if f_a < f_b:
    x = 1
else:
    x = -1

s_a = f_a + t[1]*a[1]
s_b = f_b + t[1]*b[1]
if s_a < s_b:
    y = 1
else:
    y = -1

if s_a==s_b:
    print('infinity')
else:
    if x==y:
        print(0)
    else: 
        s = abs(f_a-f_b)
        t = abs(s_a-s_b)
        print((s//t*2)+(s%t!=0))
