t = int(input())
for i in range(t):
    a, y = map(int, input().split())
    if a == y or a-y==1 or a>y:
        print("YES")
    else:
        if a == 1:
            print("NO")
        elif a == 3:
            print("NO")
        elif a==2 and y!=3:
            print("NO")
        else:
            print("YES")

"""
    Debdip Das Dipto
    
"""               