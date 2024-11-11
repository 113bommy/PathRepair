N = int(input())
A = map(int, input().split(" "))

oe = [a%2 for a in A]
if sum(oe)%2 == 0:
    print("YES")
else:
    print("NO")