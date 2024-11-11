N,K=map(int,input().split())
td=[]
for i in range(N):
    t,d=map(int,input().split())
    td.append([t,d])
td.sort(key=lambda x:x[1],reverse=True)
A=td[:K]
B=[]
s2=set()
for i,j in td[K:]:
    if not(i in s2):
        s2.add(i)
        B.append([i,j])
s1=set()
n=0
C=[]
sum=0
for i,j in A:
    if not(i in s1):
        s1.add(i)
        n+=1
        sum+=j
    else:
        C.append([i,j])
        sum+=j
sum+=n**2
B.reverse()
D=[]
for i,j in B:
    if not(i in s1):
        D.append([i,j])
list=[sum]

while(C):
    if D:
        i,j=D.pop()
        list.append(list[-1]+2*n+1+(j-C[-1][1]))
        n+=1
    C.pop()
print(max(list))
