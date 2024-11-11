h, w, n = map(int, input().split())
sr, sc = map(int, input().split())
S = input()
T = input()
win = 0

SR = sr
SC = sc
sr = SR
sc = SC
for i in range(n):
    if S[i] == "L":
        sc -= 1
    if sc <= 0:
        break
    if T[i] == "R" and sc < w:
        sc += 1
if sc <= 0:
    win = 1


sr = SR
sc = SC
for i in range(n):
    if S[i] == "R":
        sc += 1
    if sc > w:
        break
    if T[i] == "L" and sc > 1:
        sc -= 1
if sc > w:
    win = 1


sr = SR
sc = SC
for i in range(n):
    if S[i] == "D":
        sr += 1
    if sr > h:
        break
    if T[i] == "U" and sr > 1:
        sr -= 1
if sr > h:
    win = 1


sr = SR
sc = SC
for i in range(n):
    if S[i] == "U":
        sr -= 1
    if sr <= 0:
        break
    if T[i] == "D" and sr < h:
        sr += 1
if sr <= 0:
    win = 1

if win:
    print("NO")
else:
    print("YES")
