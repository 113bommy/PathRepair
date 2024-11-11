n = int(input())
a = int(input())
b = int(input())
for i in range(0, n//min(a, b)+1):
    t = n - i*a
    if t%b == 0 and t>=0:
        ans = 'YES'
        val = [i, t//b]
        break
    else :
        ans = "NO"
if ans == "NO":
    print("NO")
else :
    print(ans)
    print(*val)
