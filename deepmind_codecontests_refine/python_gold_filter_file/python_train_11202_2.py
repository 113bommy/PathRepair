a = input()
aa = []
for i in range(len(a)):
    aa.append(a[i])
for i in range(len(aa)):
    aa.append(aa[i].upper())
for i in range(10):
    aa.append(str(i))

b = input()
bb = []
for i in range(len(b)):
    bb.append(b[i])
for i in range(len(bb)):
    bb.append(bb[i].upper())
for i in range(10):
    bb.append(str(i))

s = input()
ss=[]
o = ''
for i in range(len(s)):
    ss.append(s[i])
for i in range(len(ss)):
    j = aa.index(ss[i])
    o += bb[j]

print(o)
