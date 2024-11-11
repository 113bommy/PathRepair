a=list(input())
a[1]=int(a[1])-1
a[0]=ord(a[0])-97

b=list(input())
b[1]=int(b[1])-1
b[0]=ord(b[0])-97

print(max(abs(a[1]-b[1]),abs(a[0]-b[0])))
while a!=b:
    dd=''
    if a[0]<b[0]:
        dd+='R'
        a[0]+=1
    elif a[0]>b[0]:
        dd+='L'
        a[0]-=1
        
    if a[1]>b[1]:
        dd+='D'
        a[1]-=1
    elif a[1]<b[1]:
        dd+='U'
        a[1]+=1
    print(dd)

    

    
        







    


