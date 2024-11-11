n = int ( input ( ))
z=[]
for i in range ( n ) :
    a = list(map(int,input().split()))
    e=a[0]//a[1]
    e-=a[3]//a[1] - ((a[2]-1)//a[1])
    z +=[e]
for i in z:
    print ( i )
            
