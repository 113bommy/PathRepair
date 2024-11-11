s=str(input())
link=[]
pearl=[]
for i in s:
    if i=='-':
        link.append(i)
    else:
        pearl.append(i)
        
l=len(link)
p=len(pearl)
if p==0:
    print('YES')    
else:
    if l%p==0:
        print('YES')
    else:
        print('NO')