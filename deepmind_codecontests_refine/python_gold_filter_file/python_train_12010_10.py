n=int(input())
a=list(map(int,input().split()))
b=sorted(a)
if n==1 or b[0]==b[-1]:
    print('NO')
else:
    for i in range(n):
        if b[i]<b[i+1]:
            print(b[i+1])
            break
        
        
    
