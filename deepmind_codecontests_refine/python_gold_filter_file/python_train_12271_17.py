n = int(input())
for i in range(0, n):
    a,b,c = map(int, input().split())
    if a*a+b*b==c*c or a*a+c*c==b*b or b*b+c*c==a*a:
        print("YES")
    else:
        print("NO")