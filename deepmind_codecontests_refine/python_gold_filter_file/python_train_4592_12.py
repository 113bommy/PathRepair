n=int(input())
def primc(io):
    if io==1:
        return True;
    for i in range(2, int(io**0.5)+1):
        if (io % i) == 0:
            return False
    return True

for i in range(n):
    a=input().split(" ")
    if(int(a[0])-int(a[1])==1):
        o=int(a[0])+int(a[1])
        oi=int(a[0])-int(a[1])
        an=primc(o*oi)
        if an:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
