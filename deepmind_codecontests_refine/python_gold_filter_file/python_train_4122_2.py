x = eval(input())
s = str(x)
res = ""
for c in s:
    res += "+" * ord(c) + ".>"
print(res)