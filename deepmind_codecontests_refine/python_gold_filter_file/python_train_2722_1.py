t = int(input())
l1 = []
for x in range(t):
    l1.append(list(input()))
for x in range(1,t-1):
    for y in range(1,t-1):
        done=0
        if l1[x][y]!=".":
            done = 1
        if not done and l1[x][y-1]!=".":
            done = 1
        if not done and l1[x][y+1]!=".":
            done=1
        if not done and l1[x-1][y]!=".":
            done =1
        if not done and l1[x+1][y]!=".":
            done=1
        if not done:
            l1[x][y]="#"
            l1[x-1][y]="#"
            l1[x][y-1]="#"
            l1[x+1][y]="#"
            l1[x][y+1]="#"
#print(l1)
ruined=0
for x in l1:
    if "." in x:
        print("NO")
        ruined=1
        break
if not ruined:
    print("YES")

