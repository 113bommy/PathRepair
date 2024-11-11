l=list(input())
if l.count("-")==0:
    print("YES")
    exit()
if l.count("o")==0:
    print("YES")
    exit()
if l.count("-")%l.count("o")==0:
    print("YES")
    exit()
print("NO")