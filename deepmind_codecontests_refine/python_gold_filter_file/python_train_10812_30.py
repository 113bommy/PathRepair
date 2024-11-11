s = input()
ans = ""
k = int(input())
x = "abcdefghijklmnopqrstuvwxyz"

for i in range(len(s)-1):
    if (26-(ord(s[i])-ord("a")))%26 <= k:
        ans += "a"
        k -= (26-(ord(s[i])-ord("a")))%26 
    else:
        ans += s[i]

last = x[(ord(s[-1])-ord("a")+k)%26]
ans += last

print(ans)
