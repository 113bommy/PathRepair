#import 
a = input()
b = input()
h1 = int(a[:a.find(':')])
h2 = int(b[:b.find(':')])
m1 = int(a[a.find(':') + 1:])
m2 = int(b[b.find(':') + 1:])
t1 = h1 * 60 + m1
t2 = h2 * 60 + m2
d = (t2 - t1) // 2
#print(d)
z = str((m1 + d % 60) % 60)
if (len(z) == 1):
	z = "0" + z
w = str(h1 + d // 60 + (m1 + d % 60) // 60)
if (len(w) == 1):
	w = "0" + w
print(w + ":" + z)