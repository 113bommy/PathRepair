n=int(input())
a = " I hate"
b = " I love"
c = " that"
ans = ""
for i in range (n):
    if i != 0:
        ans += c
    if i%2 == 0:
        ans += a
    else:
        ans += b
ans += " it"
print(ans)