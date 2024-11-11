t=int(input())
k=0
for i in range(t):
    a,b,c=map(int,input().split(' '))
    if(a+b+c>=2):
        k+=1
print(k)
