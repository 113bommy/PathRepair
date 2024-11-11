a , b , c , d = list(map(int , input().split()))
r = max(3*a // 10 , a-(a*c//250))
s = max(3*b // 10 , b-(b*d//250))

if r > s:
    print("Misha")
else:
    if r < s:
        print("Vasya")
    else:
        print("Tie")
