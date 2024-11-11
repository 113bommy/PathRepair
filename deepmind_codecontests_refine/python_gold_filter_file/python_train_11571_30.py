n,v=map(int,input().split())

if (n-1)<=v:
    print(n-1)
else:
    price=v-1
    for i in range(1,(n-v+1)):
        price+=i
        
    print(price)