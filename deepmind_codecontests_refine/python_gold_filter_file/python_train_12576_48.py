N = int(input())
ans = 0
a = 0
b = 0
ab = 0
for i in range(N):
    s = input()
    ans += s.count("AB")
    a += s[-1]=="A"
    b += s[0]=="B"
    ab += (s[-1]=="A" and s[0]=="B")
if a==b==ab:
    if a!=0:
    	ans += a - 1
else:
    ans += min(a, b)
print(ans)
