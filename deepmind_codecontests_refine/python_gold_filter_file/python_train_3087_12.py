n=int(input())
l1=input()

l1
r=''
l=['a','e','i','o','u','y']
i=0
for i1 in range(n*100):
    
    try:
        if l1[i] in l and l1[i+1] in l:
            l1=l1[:i+1]+l1[i+2:]
            i=0
        else:
            i+=1
    except:
        i=0
print(l1)

    
