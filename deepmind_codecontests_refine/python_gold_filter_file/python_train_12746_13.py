import sys
input=sys.stdin.readline
s=input()
s=s.strip()
z=s[::-1]
l=["A","H","I","M","O","T","U","V","W","X","Y"]
if(s==z):
    f=0
    for i in s:
        if(i in l):
            continue
        else:
            f=1
            # print(i)
            break
    if(f==1):
        print("NO")
    else:
        print("YES")

else:
    print("NO")