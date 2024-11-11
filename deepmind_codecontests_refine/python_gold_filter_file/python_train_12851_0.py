[n,m]=[int(x) for x in input().split(' ')]
need=[int(x) for x in input().split(' ')]
list=[[i,0] for i in range(n)]
# list[0][1]+=m
try:
    while len(list)!=0:
        while (list[0][1])>=(need[(list[0][0])]):
            temp=list.pop(0)
        else:
            list[0][1]+=m
            j=list.pop(0)
            list.append(j)
except IndexError:
    pass
print(temp[0]+1)

