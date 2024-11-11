k,a,b = map(int,input().split())
i = a//k
j = b//k
z = j-i
if a%k==0 :
    z+=1
print (z)
