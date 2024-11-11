l=[]
flag=0
for i in range(8):
    l.append(input())
    for j in range(1,8):
        if(l[i][j]==l[i][j-1]):
            flag=1
            break
if(flag==1):
    print("NO")
else:
    print("YES")
    
    