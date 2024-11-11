x,y=map(int,input().split())
S = input()

g = S.index("G")
t = S.index("T")
if g < t:
    g, t = t, g
    
v=True
if (g - t) % y != 0:
    v = False
for i in range(t, g + 1, y):
    if S[i] == '#':
        v=False
        break
if v:
    print("YES")
else:    
    print("NO")
    