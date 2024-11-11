l=[]
for i in range(3):
    l.append(int(input()))
print(max(l[0]+l[1]+l[2],l[0]*l[1]*l[2],(l[0]+l[1])*l[2],l[0]*(l[1]+l[2])))