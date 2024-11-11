s = input()
 
ans = 0
s = s.replace("BC","D")
cnt_A = 0
 

for i in s:
    if i == "A":
        cnt_A += 1
    elif i == "D":
        ans += cnt_A
    else:
        cnt_A = 0

print(ans)