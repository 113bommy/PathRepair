a,b=map(int,input().split())
i=1
while(i<100):
    x=a%b
    if x==0:
        print("Yes")
        break
    a+=x
    i+=1
else:
    print("No")