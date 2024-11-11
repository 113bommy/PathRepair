a = input('')
b = input('')
c = a.split(' ')
d = b.split(' ')
x = int(c[1])
m = 0
for i in range(int(c[0])):
    if int(d[i]) <= x:
        m = m + 1
    elif int(d[i]) > x:
        m = m + 2
print(m)