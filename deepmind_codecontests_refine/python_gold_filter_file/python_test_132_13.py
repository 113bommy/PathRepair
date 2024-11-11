user1=int(input())
for z in range(user1):
    user2=input().split( )
    lst=[]
    for i in user2:
        lst.append(int(i))


    lst2=[lst[0],lst[1]]
    
    for i in range (2,len(lst)):
    
        if lst[0]+lst[1]+lst[i]==lst[-1]:
            lst2.append(lst[i])
            break
    for j in lst2:
        print(j,end=(' '))
    print()