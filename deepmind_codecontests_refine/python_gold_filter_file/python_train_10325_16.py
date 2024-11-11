n = int(input())
l = list(map(int,input().split()))
s = sum(l)%2
if s == 0 and max(l) <= sum(l)-max(l):
    print("YES")

else:
    print("NO")
