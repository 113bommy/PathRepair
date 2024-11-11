# key not available ""
n = int(input())
s1 = "ROYGBIV"
s = "ROYGBIV"
s2 = "GBIV"
x = n // 7
rem = n % 7
if x > 0:
    s = s * x
else:
    s = ""
if rem <= 3:
    for i in range(rem):
        s += s2[i]
else:
    for i in range(rem):
        s += s1[i]
print(s)