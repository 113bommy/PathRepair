import sys
t = int(sys.stdin.readline())
while t:
    x,y,z = map(int,sys.stdin.readline().strip().split())
    if [x,y,z].count(max(x,y,z))<2:
        print("NO")
    else:
        print("YES")
        print(max(x,y,z),min(x,y,z),min(x,y,z))
    t-=1