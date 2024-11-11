for _ in range(int(input())):
    l=list(map(int,input().split()))
    l.sort()
    if l[0]<=l[1] and l[1]==l[2]:
        print("YES")
        print(l[0],l[0],l[2],end=" ")
        print("")
    else:
        print("NO")