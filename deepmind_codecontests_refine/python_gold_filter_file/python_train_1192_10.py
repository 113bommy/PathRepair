g = 'qwertyuiopasdfghjkl;zxcvbnm,./'
a = input()
b = input()
c = ''
for i in range(len(b)):
    if a == 'R':
        c += g[g.index(b[i])-1]
    elif a == 'L':
        c += g[g.index(b[i])+1]
print(c)