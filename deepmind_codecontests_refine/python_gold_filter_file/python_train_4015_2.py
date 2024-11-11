n=int(input())
x=input()
s=0
k=0
l=[]
for i in x :
    if i =='B' :
        s+=1
    else :
        if s!=0 :
            k+=1
            l.append(s)
            s=0
if s != 0 :
    k+=1
    l.append(s)
print(k)
for i in l :
    print(i,end=' ')