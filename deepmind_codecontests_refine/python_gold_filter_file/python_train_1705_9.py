arr=[int(x) for x in input().split()]
n,m=arr[0],arr[1]
mini=min(n,m)
print(mini+1)
i=0
while(mini>=0):
    print(mini,i)
    mini-=1
    i+=1
    