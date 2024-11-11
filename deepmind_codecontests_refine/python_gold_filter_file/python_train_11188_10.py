x=[]
y=[]
for i in range(int(input())):
    s,t=input().split()
    if s not in x and s not in y:
        x.append(s)
        y.append(t)
    else:
        y[y.index(s)] = t
print(len(x))
for i in range(0,len(x)):
    print(x[i],y[i])