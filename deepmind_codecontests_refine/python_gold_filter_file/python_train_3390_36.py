x=list(map(int,input().split()))
l=[]
f=0
for i in range(x[0]):
        l.append(list(map(str,input().split())))
for i in l:
    for j in i:
        if j in ['C','M','Y']:
            f=1
            break
if f==1:
    print('#Color')
else:
    print('#Black&White')
    
