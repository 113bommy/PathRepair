n,m,k = map(int,input().split())
a = n * m 
num = 0
for i in range(k-1):
    print(a // k,end=" ")
    for j in range(a // k):
        if((num // m)%2 == 1):
            print((num // m) + 1, m - (num % m),end=" ")
        else:
            print((num // m) + 1 , (num % m) + 1,end=" ")
        num += 1
    print()
print(a - num,end=" ")
while(num < a):
    if((num // m)%2 == 1):
        print((num // m) + 1, m - (num % m),end=" ")
    else:
        print((num // m) + 1 , (num % m) + 1,end=" ")
    num += 1