#ALDS1_3-B Elementary data structures - Queue
n,q = [int(x) for x in input().split()]
Q=[]
for i in range(n):
    Q.append(input().split())
t=0
res=[]
while Q!=[]:
    if int(Q[0][1])<=q:
        res.append([Q[0][0],int(Q[0][1])+t])
        t+=int(Q[0][1])
    else:
        Q.append([Q[0][0],int(Q[0][1])-q])
        t+=q
    del Q[0]
for i in res:
    print(i[0]+" "+str(i[1]))