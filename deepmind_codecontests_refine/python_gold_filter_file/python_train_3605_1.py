n =int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
if n > 2 :
    s = sum(a)
    b1 = max(b)
    b.remove(b1)
    b2 = max(b)
    if s <= b1 + b2 :
        print("YES")
    else:
        print("NO")
else:
    print("YES")