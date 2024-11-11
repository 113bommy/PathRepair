m,n = map(int, input().split())
str1, str2, str3 = "", "", ""
for i in range(n):
    str1 = str1 + "#"
    if i == 0:
        str2 = str2 + "#"
    else:
        str2 = str2 + "."
    if i == n-1:
        str3 = str3 + "#"
    else:
        str3 = str3 + "."

for i2 in range(1, m+1):
    if i2%2 != 0:
        print(str1)
    else:
        if i2%4 == 0:
            print(str2)
        else:
            print(str3)