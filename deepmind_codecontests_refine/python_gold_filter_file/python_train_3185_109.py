a,b=map(int,input().split())
cnt=0
while(a<=b):
    a=3*a
    b=2*b
    cnt+=1
print(cnt)