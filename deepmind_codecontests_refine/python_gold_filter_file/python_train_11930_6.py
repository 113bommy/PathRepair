n,t,k,d=map(int,input().split())

#number of needed cakes
#time to bake k
#k
#time to build 2nd one takes t to bake k also


if(d/t<1):
    if(n-k>0):
     print("YES")
    elif(n-k<=0):
     print("NO")

else:
    from math import ceil
    if((n-ceil(d/t)*k<=k and (ceil(d/t)+1)*t<=d+t) or n-ceil(d/t)*k<=0):
        print("NO")
    else:
        print("YES")