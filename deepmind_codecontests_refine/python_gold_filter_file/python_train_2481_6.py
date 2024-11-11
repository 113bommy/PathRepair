n=int(input())
d,x=map(int,input().split())
for i in range(n):
    a=int(input())
    x+=1+(d-1)//a
print(x)