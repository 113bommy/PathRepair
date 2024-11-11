for _ in range(int(input())):
    a=input()
    b=input()
    c=input()
    for i in range(len(a)):
        if a[i]!=b[i] and b[i]!=c[i] and c[i]!=a[i]:
            print("NO");break
        elif a[i]==b[i] and a[i]!=c[i]:
            print("NO")
            break
    else:print("YES")