k=int(input())
lst=[]
str1=[]
str1.append('c')
str1.append('o')
str1.append('d')
str1.append('e')
str1.append('f')
str1.append('o')
str1.append('r')
str1.append('c')
str1.append('e')
str1.append('s')
for i in range(10):
    lst.append(1)
prod=1
flag=0
while True:
    for i in range(len(lst)):
        if prod>=k:
            flag=1
            break
        prod=int(prod/lst[i])
        lst[i]+=1
        prod=prod*lst[i]
    if prod>=k:
        break
    if flag:
        break
str2=""
c=-1
#print(prod)
for i in lst:
    c+=1
    for j in range(i):
        str2+=str1[c]
print(str2)
    
                
        