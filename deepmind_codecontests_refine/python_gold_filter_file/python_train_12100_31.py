t = int(input())
output = []
for j in range(t):
    s = (str(input())).split(" ")
    x = int(s[0])
    y = int(s[1])
    a = int(s[2])
    b = int(s[3])
    ans = (y - x)//(a + b) if (y - x)%(a + b) == 0 else -1
    output.append(ans)
for i in output:
    print(i)