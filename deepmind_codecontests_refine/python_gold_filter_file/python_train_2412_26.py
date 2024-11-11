n=int(input())
y=(n-3)//2
if(n%2==0 or y<=0):
    print("NO")
else:
    print(1,end=' ')
    print(y)