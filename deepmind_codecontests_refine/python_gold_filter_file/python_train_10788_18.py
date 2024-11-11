
l, r = 0, 0
for i in range(int(input())):
    x, y=map(int,input().split())
    if x < 0: l+=1
    else: r+=1
if l < 2 or r < 2: print("Yes")
else:print("No")    