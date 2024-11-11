n = int(input())
for i in range(n):
    a,b = [int(i) for i in input().split(' ')]
    if a==1 or b==1:
        print("YES")
    elif a==2 and b==2:
        print("YES")
    else:
        print("NO")