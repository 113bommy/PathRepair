def mi():
        return map(int, input().split())
'''
3 5 1 3
1 1 2
2 2 3
3 3 3
4 1 1
10 1 3
'''
n,m,s,f = mi()
t = [0]*m
l = [0]*m
r = [0]*m
for i in range(m):
        t[i],l[i],r[i] = mi()
curp = s
curt = 1
i = 0
a = ''
if f>s:
        a = (f-s)*'R'
else:
        a = (s-f)*'L'
while i<m and curp!=f:
        if t[i]==curt:
                if a[0]=='R' and curp+1>=l[i] and curp+1<=r[i]:
                        print ('X', end = '')
                elif a[0]=='L' and curp-1>=l[i] and curp-1<=r[i]:
                        print ('X', end = '')
                elif curp>=l[i] and curp<=r[i]:
                        print ('X', end = '')
                elif a[0]=='R':
                        curp+=1
                        print(a[0], end = '')
                else:
                        curp-=1
                        print (a[0], end = '')
                i+=1
        elif a[0]=='R':
                curp+=1
                print(a[0], end = '')
        else:
                curp-=1
                print (a[0], end = '')

        curt+=1
if f>curp:
        print ((f-curp)*'R')
elif curp>f:
        print ((curp-f)*'L')
