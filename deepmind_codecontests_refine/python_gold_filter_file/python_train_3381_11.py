a,b,s = map(int, input().split())
min_steps = abs(a)+abs(b)
if s<min_steps:
    print("NO")
else:
    if (s - min_steps)%2==0:
        print("YES")
    else:
        print("NO")