n,k=[int(i) for i in input().split()]
s=input()
m=n+1
asc=65
for i in range(1,k+1):
    m=min(m,s.count(chr(asc)))
    asc+=1
    
if(m!=0) : print(m*k)
else : print('0')