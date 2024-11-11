c=[0] * 52
for i in range(13):
    c[i]='S {0}'.format(i+1)
    c[13+i]='H {0}'.format(i+1)
    c[26+i]='C {0}'.format(i+1)
    c[39+i]='D {0}'.format(i+1)

for i in range(int(input())):
    c.remove(input())

if c:print('\n'.join(c))
