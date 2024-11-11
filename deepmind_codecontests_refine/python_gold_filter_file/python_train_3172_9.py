n=int(input())
l=[]
mix=1000000000
miy=1000000000
max=-1000000000
may=-1000000000
for i in range(n):
    l.append(list(map(int,input().split())))
    if l[i][0]<mix:
        mix=l[i][0]
    if l[i][0]>max:
        max=l[i][0]
    if l[i][1]<miy:
        miy=l[i][1]
    if l[i][1]>may:
        may=l[i][1]
'''print("max,may,mix,miy=",max,may,mix,miy)'''
if abs(max-mix)>abs(may-miy):
    print((max-mix)**2)
else:
    print((may-miy)**2)
