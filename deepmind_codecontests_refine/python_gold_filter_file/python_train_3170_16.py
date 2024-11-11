countB=0
countA=0
l=[]
for i in [0]*int(input()):
    l.append(input())

for j in l:
    if j==l[0]:
        countA+=1
    else:
        m=j
        countB+=1

if countA>countB:
    print(l[0])
else:
    print(m)
