n=int(input())
a=0
for i in range(n-1):
    if(a%2==0):
        print ("I hate that",end=" ")
    else:
        print ("I love that",end=" ")
    a+=1
if(a%2==0):
    print ("I hate it")
else:
    print ("I love it")