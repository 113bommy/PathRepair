a,b = input().split()
l = list(map(int, input().split()))
x= len(l)
v= max(l)
w= sum(l)-v
if w<=int(b):
    print("YES")

else:
    print("NO")