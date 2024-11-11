k = "13579aeiouAEIOU"
s = input()
answer = 0
for i in range(len(s)):
    if  s[i] in k:
        answer += 1
print(answer)