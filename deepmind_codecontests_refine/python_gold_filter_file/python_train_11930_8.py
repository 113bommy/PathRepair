ntdk = input().strip().split(' ')
n = int(ntdk[0])
t = int(ntdk[1])
k = int(ntdk[2])
d = int(ntdk[3])


if n<=k:
    print('NO')
else:
    if d<t:
        print('YES')
    elif n-(d//t)*k>k:
        print('YES')
    else:
        print('NO')

        
        
    
