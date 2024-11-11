a=int(input())
l=[]
i=1
while i<=a: 
    l.append(str(i))
    i+=1
i=a-1
while i>0: 
    l[i],l[i-1]=l[i-1],l[i]
    i-=1
print(" ".join(l))