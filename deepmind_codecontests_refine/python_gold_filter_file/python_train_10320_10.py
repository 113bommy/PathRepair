n=int(input())
e=n
dic={}
dety=[]
for i in range(n):
    a,b=[int(x) for x in input().split()]
    if a in dic:
        dic[a].append(b)
    else:
        dic[a]=[b]
    if b in dic:
        dic[b].append(a)
    else:
        dic[b]=[a]
    dety.append((a,b))
tot=[]
item=1
prev=0
while n>0:
    if prev==dic[item][0]:
        prev=item
        tot.append(dic[item][1])
        item=dic[item][1]
    else:
        prev=item
        tot.append(dic[item][0])
        item=dic[item][0]
    n-=1
if tot.index(1)!=e-1:
    if tot[tot.count(1)+1]!=dety[0][0] and tot[tot.count(1)+1]!=dety[0][1]:
         tot.reverse()
else:
    if tot[tot.index(2)+1]!=dety[1][0] and tot[tot.index(2)+1]!=dety[1][1]:
         tot.reverse()
total=''
for item in tot:
    total+=str(item)+' '
print(total[:-1])
    
