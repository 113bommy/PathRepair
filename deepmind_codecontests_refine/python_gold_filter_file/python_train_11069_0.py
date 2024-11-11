s=input()
u=input()
t=[0]*len(s)
d={i :[] for i in "abcdefghijklmnopqrstuvwxyz" }
for i,j in enumerate(s) :
    d[j].append(i)
for i in u:
    for j in d[i]:
        t[j]=t[j]+1
    t=[0]+t
    #print(t)
print(len(u)-max(t))  
    