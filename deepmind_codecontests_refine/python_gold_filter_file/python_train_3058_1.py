a,b,c=map(int,input().split())

for i in range(10):
    y=a*10+i
    #print(y)
    if (y%b)==0:
        #print(y)
        y=y*(10**(c-1))
        print(y)
        exit(0)
print(-1)