n = int(input())
s = input().strip()

flag = False
if n % 2 != 0 or s.startswith(')))') or s.endswith("((("):
    flag = True

count1 = [0]*n
count2 = [0]*n
S = 0
for i in range(n):
    if s[i] == '(':
        S += 1
    else:
        S -= 1
    if S < 0:
        for j in range(i,n):
            count1[j] = -1
        break
    else:
        count1[i]  = S
S = 0
for i in range(n-1,-1,-1):
    if s[i] == ')':
        S += 1
    else:
        S -= 1
    if S < 0:
        for j in range(i+1):
            count2[j] = -1
        break
    else:
        count2[i] = S
# print("count1",count1)
# print("count2",count2)

ans = 0
if n == 2 and (abs(count1[-1])== 2 or abs(count2[0]) == 2):
    ans += 1
for i in range(1,n-1):
    if count1[i-1] >= 0 and count2[i+1] >= 0:
        if s[i] == '(' and count1[i-1] == count2[i+1] + 1:
            # print("i1",i)
            ans += 1
        if s[i] == ')' and count1[i-1] + 1 == count2[i+1]:
            # print("i2", i)
            ans += 1
print(ans)