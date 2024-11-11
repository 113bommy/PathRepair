res = ""
s = input()

if s[:4] == "http":
    res += s[:4]
    s = s[4:]
elif s[:3] == "ftp":
    res += s[:3]
    s = s[3:]

res += "://"

pos = 0
for i in range(1, len(s)):
    pos = i
    if s[i:i+2] == "ru":
        break

res += s[:pos] + ".ru"
s = s[pos+2:]

if len(s) > 0:
    res += "/" + s

print(res)
