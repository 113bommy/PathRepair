import sys
import math
def II():
	return int(sys.stdin.readline())
 
def LI():
	return list(map(int, sys.stdin.readline().split()))
 
def MI():
	return map(int, sys.stdin.readline().split())
 
def SI():
	return sys.stdin.readline().strip()
n = II()
a = LI()
rows = [0]*n
columns = [0]*n
q = []
q2 = []
l2 = 0
l = 0
row = n-1
ans = []
boo = True
for i in range(n-1,-1,-1):
    if row == -1 and a[i]!=0:
        boo = False
        break
    if a[i] == 1:
        q.append([row,i])
        ans.append([row+1,i+1])
        columns[i]+=1
        rows[row]+=1
        row-=1
    elif a[i] == 2:
        if l == len(q):
            boo = False
            break
        x = q[l][0]
        l+=1
        rows[x]+=1
        columns[i]+=1
        q2.append([x, i])
        ans.append([x+1, i+1])
        row-=1
    elif a[i] == 3:
        if l == len(q) and l2 == len(q2):
            boo = False
            break
        if l2 != len(q2):
            x = q2[l2][1]
            l2+=1
        else:
            x = q[l][1]
            l+=1
        rows[row]+=2
        columns[i]+=1
        columns[x]+=1
        ans.append([row+1,x+1])
        ans.append([row+1, i+1])
        q2.append([row,i])
        row-=1
for i in range(n):
    if rows[i]>2:
        boo = False
        break
for i in range(n):
    if columns[i]>2:
        boo = False
        break
if not boo:
    print(-1)
else:
    print(len(ans))
    for i in ans:
        print(*i)

