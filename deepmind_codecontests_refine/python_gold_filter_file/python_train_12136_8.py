input()
s = input().strip()
r = ""
l = len(s)
for i in s:
    if l % 2 == 0:
        r = i + r 
    else:
        r = r + i 
    l -= 1 
print(r)