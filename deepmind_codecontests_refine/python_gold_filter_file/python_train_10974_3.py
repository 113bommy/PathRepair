n=int(input())
count=0
a=[[0 for _ in range(n)]for _ in range(n)]
print((n*n+1)//2)
for i in range(n):
    for j in range(n):
        if i==2:
            break
        if i==0:
            if j==0 or j%2==0:
                a[i][j]='C'
    
            else:
                a[i][j]='.'
                
        elif i==1:
            if a[i-1][j]!='C':
                a[i][j]='C'
            
            else:
                a[i][j]='.'
                
for i in range(n):
    if i%2!=0:
        print(''.join(a[1]))
    else:
        print(''.join(a[0]))