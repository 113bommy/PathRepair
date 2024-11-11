lst = []
i = int(input())
for i in range(0,i):
    lst.append(input().split())


for i in range(0,len(lst)):
    x = int(lst[i][0])
    y = int(lst[i][1])
    if y>x:
        print("NO")
        continue
    if x%2!=0 and y%2==0:
        print('NO')
        continue
    if x%2==0 and y%2==0:
        lst1 = [1]*(y-1)
        lst1.append(x+1-y)
        print("YES")
        for j in lst1:
            print(j,end=" ")
        print("\n",end="")
    elif x%2==0 and y%2!=0:
        if x>=y*2:
            lst1 = [2]*(y-1)
            lst1.append(x+2-2*y)
            print("YES")
            for j in lst1:
                print(j,end=" ")
            print("\n",end="")
        else:
            print("NO")
    else:
        lst1 = [1]*(y-1)
        lst1.append(x+1-y)
        print("YES")
        for j in lst1:
            print(j,end=" ")
        print("\n",end="")