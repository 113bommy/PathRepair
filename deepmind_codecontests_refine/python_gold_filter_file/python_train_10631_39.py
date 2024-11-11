n=int(input())
a=list(map(int,input().split()))
yo=pow(10,5)+5

print(n+1)
print(1,n,yo)
for i in range(n):
    print(2,i+1,a[i]+yo-i)
