n=int(input())
a=int(input())
b=int(input())
for i in range(0,n):
    if (n-i*b)%a==0 and n-i*b>=0:
        print("YES")
        print((n-i*b)//a,i)
        exit()
print("NO")