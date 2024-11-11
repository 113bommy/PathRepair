X=int(input())

a=100
cnt=0
while a<X:
    a=a+a//100
    cnt+=1
print(cnt)