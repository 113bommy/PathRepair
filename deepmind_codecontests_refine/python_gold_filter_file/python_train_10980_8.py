n, s, total = int(input()), input(), 0
hash = dict({})

for i in range(0, 2 * n - 2, 2):

    if (s[i].upper() != s[i + 1]):
        if (s[i + 1] in hash and hash[s[i + 1]]):
            hash[s[i + 1]] = hash[s[i + 1]] - 1
        else:
            total += 1

        if (s[i].upper() in hash):
            hash[s[i].upper()] += 1
        else:
            hash[s[i].upper()] = 1

print(total)
