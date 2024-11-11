i=int(input())
o=True
j=10
c=[]
while o==True:
    if j%2==0 or j%3==0:
        if (j+i)%2==0 or (j+i)%3==0:
            c.append(j)
            c.append(j+i)
            break
    if len(c)!=0:
        break
    else:
        j+=1
print(str(c[1])+" "+str(c[0]))