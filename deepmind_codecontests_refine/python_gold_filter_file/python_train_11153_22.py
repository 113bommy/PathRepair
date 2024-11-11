n = int(input())
s = input()

s1 = 'RGB'*((n-1)//3+1)
s2 = 'GRB'*((n-1)//3+1)
s3 = 'BGR'*((n-1)//3+1)
s4 = 'BRG'*((n-1)//3+1)
s5 = 'RBG'*((n-1)//3+1)
s6 = 'GBR'*((n-1)//3+1)
ans1 = 0
ans2 = 0
ans3 = 0
ans4 = 0
ans5 = 0
ans6 = 0

for i in range(n):
    if s[i] != s1[i]:
        ans1 += 1
    if s[i] != s2[i]:
        ans2 += 1
    if s[i] != s3[i]:
        ans3 += 1
    if s[i] != s4[i]:
        ans4 += 1
    if s[i] != s5[i]:
        ans5 += 1
    if s[i] != s6[i]:
        ans6 += 1
ans = min(ans1, ans2, ans3, ans4, ans5, ans6)
print(ans)
if ans == ans1:
    print(s1[:n])
elif ans == ans2:
    print(s2[:n])
elif ans == ans3:
    print(s3[:n])
elif ans == ans4:
    print(s4[:n])
elif ans == ans5:
    print(s5[:n])
elif ans == ans6:
    print(s6[:n])

