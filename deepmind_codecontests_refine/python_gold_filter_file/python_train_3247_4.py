x=int(input())
for __ in range(x):
    n=int(input())
    a=input()
    b=input()
    z="a"
    f=0
    for i in range(n):
        if z=="a":    
            if a[i]=="3" or a[i]=="4" or a[i]=="5" or a[i]=="6":
                if b[i]=="3" or b[i]=="4" or b[i]=="5" or b[i]=="6":
                    z="b"
                else:
                    f=1
                    break
        elif z=="b":        
            if b[i]=="3" or b[i]=="4" or b[i]=="5" or b[i]=="6":
                if a[i]=="3" or a[i]=="4" or a[i]=="5" or a[i]=="6":
                    z="a"
                else:
                    f=1
                    break
    if z=="b" and f==0:
        print("YES")
    else:
        print("NO")