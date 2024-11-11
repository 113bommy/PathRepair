n = int(input())
s = input()
s = s.split()
d = []
m1 = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
m2 = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
m3 = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
m = []
m.append(m1)
m.append(m2)
m.append(m3)

for i in s:
    d.append(int(i))

st = False
for a in m:
    if st:
        break
    for x in range(24):
        y = []
        if x+n>24:
            c1 = a[x:]
            c2 = a[:x+n-24]
            y = c1 + c2
        else:
            y = a[x:x+n]
        if y==d:
            st = True

if st:
    print('Yes')
else:
    print('No')