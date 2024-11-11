#Codeforces 1154A
x,y,z,w=[int(v) for v in input().split()]
d=[x,y,z,w]
d.sort()
a = d[3]-d[0]
b = d[3]-d[1]
c = d[3]-d[2]
print(str(a)+" "+str(b)+" "+str(c))