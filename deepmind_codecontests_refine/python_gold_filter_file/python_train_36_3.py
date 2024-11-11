n = int(input())
s = input()
c = 0
for i in s :
    if i == "I" :
        c += 1
    if c > 1 :
        ans = 0
        break
if c == 0 :
    ans = s.count("A")
elif c == 1 :
    ans = 1
print (ans)