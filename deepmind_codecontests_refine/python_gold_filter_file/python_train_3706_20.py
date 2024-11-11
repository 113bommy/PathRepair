from math import*
n,m=(list(map(int,input().split())))
def prime(a):
        x=ceil(a**.5)+1
        c=0
        for i in range(2,x):
            if a%i==0:
                c=1
                break
        if c==0:
            return a
        else:
            return -1


for i in range(n+1,51):
    if (prime(i))!=-1:
        print('YES' if prime(i)==m else 'NO')
        exit(0)

        
        

print('NO')
    
    
    
