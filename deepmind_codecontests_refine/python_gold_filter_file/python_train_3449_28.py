# for _ in range(int(input())):
n=int(input())
i = 9
qou = -1
while(i>0):
    if n%i ==0:
        qou = i
        break
    i-=1

if qou!=-1:
    print(n//qou)
    print(*[qou]*(n//qou))
else:
    if n<=1000:
        print(n)
        print(*[1]*n)
    else:
        print(n//9+1)
        print(*[9]*(n//9),n%9)
    
    
    
    
         
        
        