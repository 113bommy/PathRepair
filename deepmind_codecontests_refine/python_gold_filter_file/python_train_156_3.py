n,k=map(int,input().split(' '))
m=list(map(int,input().split(' ')))
for i in range(1,n+1):
    if (1+i)*i//2>=k:
        print(m[k-(i)*(i-1)//2-1])
        break