l=input().split(' ')
n=int(l[0])
m=int(l[1])
t=[]
i=0
for i in range(n):
    l=input().split(' ')
    t.append(int(l[0])/int(l[1]))

print(min(t)*m)
