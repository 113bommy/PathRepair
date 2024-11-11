from sys import stdin,stdout

n,m = (int(i) for i in stdin.readline().split())
x1,x2,y1,y2 = 10**6,0,0,0
c = 0
flag = False
for i in range(n):
    st = stdin.readline()
    if st.count('B') > 0:
        c += st.count('B')
        if not(flag):
            y1 = i
        flag = True
        if x1 > st.index('B'):
            x1 = st.index('B')
        if x2 < st.rindex('B')+1:
            x2 = st.rindex('B')+1
        y2 = i + 1
#print(x1,x2,y1,y2)
height = y2 - y1
widht = x2 - x1
#print(widht,height)
if c == 0:
    stdout.write('1')
else:
    if max(widht,height) > min(n,m):
        stdout.write('-1')
    else:
        stdout.write(str(max(widht,height)**2-c))
