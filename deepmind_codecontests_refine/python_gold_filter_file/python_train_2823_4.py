s=input()
c=input()
a='6789TJQKA'
if(c[1]==s and c[1]!=c[len(c)-1]):
    print("YES")
else:
    if(c[1]==c[len(c)-1] and a.find(c[0])>a.find(c[len(c)-2])):
        print("YES")
    else:
        print("NO")
        