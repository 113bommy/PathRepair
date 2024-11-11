n=int(input())
a=0
b=0
k=0
ma=0
for i in range(n) :
    l=input().split()
    if a==l[0] and b==l[1]  :
        k=k+1
    else :
        if ma<k :
            ma=k
        k=0
    a=l[0]
    b=l[1]
if ma<k :
    ma=k
print(ma+1)
