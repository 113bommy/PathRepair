n, s = int(input()), input()
k = ['a']
ans = ''
maxColor = 1
for symb in s:
    k.append('a')
    for i in range(len(k)):
        if symb >= k[i]:
            ans += str(i + 1) + ' '
            if i + 1 > maxColor:
                maxColor = i + 1
            k[i] = symb
            break
print(maxColor)
print(ans)