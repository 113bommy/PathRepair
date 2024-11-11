n, d = map(int, input().split())
s = input()
output = 0
i = 0
while i < n-1:
    if "1" not in s[i+1:i+d+1]:
        output = -1
        break
    else:
        index = d - s[i+1:i+d+1][::-1].index("1")
        i += index
        output += 1
print(output)