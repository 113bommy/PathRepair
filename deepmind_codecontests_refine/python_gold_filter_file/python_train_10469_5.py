s = input()
count = 0
if abs(ord(s[0]) - ord('a')) < 13:
    count += abs(ord(s[0]) - ord('a'))
    # print(ord(s[i + 1]) - ord(s[i]))
else:
    count += abs(26 - abs(ord(s[0]) - ord('a')))
for i in range(0, len(s) - 1):
    #print(s[i + 1])
    #print(s[i])
    #print('count = ', count)
    if abs(ord(s[i + 1]) - ord(s[i])) < 13:
        count += abs(ord(s[i + 1]) - ord(s[i]))
        #print(ord(s[i + 1]) - ord(s[i]))
    else:
        count += abs(26 - abs(ord(s[i + 1]) - ord(s[i])))
    #print('count = ', count)
print(count)