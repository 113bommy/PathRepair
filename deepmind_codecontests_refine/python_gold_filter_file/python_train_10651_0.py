d={}

for _ in range(int(input())):
    n = list(input().split())
    d[n[1]]=[0,0,0]
    for i in range(int(n[0])):
        s = list(input())
        ll=[]
        ll.append(int(s[0]))
        ll.append(int(s[1]))

        ll.append(int(s[3]))
        ll.append(int(s[4]))
        ll.append(int(s[6]))
        ll.append(int(s[7]))
        le=len(set(ll))
        ll.reverse()
        if(le==1):
            d[n[1]][1]+=1
        
        elif(sorted(ll)==ll and le == len(ll)):
            d[n[1]][0]+=1
            
        else:
            d[n[1]][2]+=1
            
        
        
x=[0,[],0,[],0,[]]

for i in d:
    if(d[i][0]>x[0]):
        x[0]=d[i][0]
        x[1]=[i]
    elif(d[i][0]==x[0]):
        x[1].append(i)

    if(d[i][1]>x[2]):
        x[2]=d[i][1]
        x[3]=[i]
    elif(d[i][1]==x[2]):
        x[3].append(i)
    
    if(d[i][2]>x[4]):
        x[4]=d[i][2]
        x[5]=[i]
    elif(d[i][2]==x[4]):
        x[5].append(i)

print("If you want to call a taxi, you should call:",end=" ")
print(*x[3], sep = ", ",end=".\n")
print("If you want to order a pizza, you should call:",end=" ")
print(*x[1], sep = ", ",end=".\n")
print("If you want to go to a cafe with a wonderful girl, you should call:",end=" ")
print(*x[5], sep = ", ",end=".\n")


    
        
