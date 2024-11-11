[a,b]=map(int,input().split())
i=1
while 0!=a*i%10!=b:
    i+=1
print(i)