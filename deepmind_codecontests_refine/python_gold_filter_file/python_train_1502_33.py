import math
f = {"B":0,"C":0,"S":0}
s = input()
for c in s:
    if c in f:
        f[c]+=1
    else:
        f[c]=1
[nb,ns,nc] = [int(i) for i in input().split() ]
[pb,ps,pc] = [int(i) for i in input().split() ]
if f["S"]==0:
    ps=0
if f["C"]==0:
    pc=0
if f["B"]==0:
    pb=0

h = int(input())
x=0
mn = 0 
mx = 100000000000000
ans = 0
while(mn<=mx):
    x = math.floor((mn+mx)/2);
    fx =  max((f['B']*x-nb),0)*pb+max((f['C']*x-nc),0)*pc+max((f['S']*x-ns),0)*ps
    if fx<h:
        mn = x+1
        ans = x
    elif fx>h:
        mx = x-1
    else:
        ans = x
        break
print(ans)