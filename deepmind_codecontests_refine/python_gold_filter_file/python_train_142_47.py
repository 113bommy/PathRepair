a=list(map(int,input().split('+')))
a=sorted(a)
print(a[0],end='')
for i in range(1,len(a)):
    print('+',a[i],sep='',end='')