n = int(input())
s = input()
d = [0]
cnt = 0
for i in range(n):
    if s[i] == "(":
        cnt += 1
    else:
        cnt -= 1
    d.append(cnt)
x = min(d)
print("("*(-x)+s+")"*(d[-1]-x))