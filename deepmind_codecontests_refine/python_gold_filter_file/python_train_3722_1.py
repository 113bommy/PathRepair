s = [int(i) for i in input()]

ans = 0
x = len(s)
#print(s)
for i in range(len(s)):
    if s[i] > 1:
        ans += 1 << x
        #print("broken")
        break
    elif s[i] == 1:
        ans += 1 << (x - 1)
    x -= 1
else:
    ans += 1
ans -= 1

print(ans)
