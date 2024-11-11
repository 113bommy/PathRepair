q=input().upper()
l=len(q)
v=('A','I','O','U','E','Y')
for i in q:
    if (65<=ord(i)<=90) or (i==" ") or (i=="?"):
        for j in range(-1,-l-1,-1):
            if 65<=ord(q[j])<=90:
                if q[j] in v:
                    print("YES")
                    break
                else:
                    print("NO")
                    break
        else:
            print("NO")
            break
    else:
        print("NO")
        break
    break