import sys
n = int(input())
s = input()
if(n == 1):
    print("YES")
    print(0)
    sys.exit()
s1, s2 = [0], []
for i in range(1, n):
    if s[i] >= s[s1[-1]]:
        s1.append(i)
    elif not s2 or s[i] >= s[s2[-1]]:
        s2.append(i)
    else:
        print("NO")
        sys.exit()

print("YES")
ans = ['0']*n
for i in s2:
    ans[i] = '1'
print("".join(ans))
