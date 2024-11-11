n=int(input())
list=[]
for i in range (n):
    cr=0
    cd=0
    
    l=[]
    x, y = input().split()
    x=int(x)
    y=int(y)
 
    for i in range(x):
        l.append(input())      
    if l==['C']:
        
        list.append(0)
        continue
    for j in range(len(l)-1):
        if l[j][-1]=='R':
            cr+=1
            
    for j in range(y):
        if l[len(l)-1][j]=='D':    
            cd+=1
    
    list.append(cr+cd)

for i in list:
    print(i)
