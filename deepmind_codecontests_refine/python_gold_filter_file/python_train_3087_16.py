n=int(input())
a=list(input())
x=['a','e','i','o','u','y']
b=[]
i=0
while i<n:
    if a[i] not in (x):
        b.append(a[i])
        #print(a)
        i+=1
    else:
        b.append(a[i])
        for j in range(i,n):
            if a[j]  in (x):
                i+=1
            else:
                break
print(''.join(b))        
            
        