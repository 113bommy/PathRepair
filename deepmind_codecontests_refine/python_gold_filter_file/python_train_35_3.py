s = input()
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
n = len(s)
d = {}
max_k = 0
max_t = ''
for i in range(n - 9):
    if s[i + 2] == '-' and s[i + 5] == '-':
        if s[i + 3: i + 5].isdigit() and 1 <= int(s[i + 3: i + 5]) <= 12:
            m = int(s[i + 3: i + 5])
            if s[i: i + 2].isdigit() and 1 <= int(s[i: i + 2]) <= months[m - 1]:
                if s[i + 6: i + 10].isdigit() and 2013 <= int(s[i + 6: i + 10]) <= 2015:
                    t = s[i: i + 10]
                    if d.get(t):
                        d[t] += 1
                    else:
                        d[t] = 1
                    if d[t] >= max_k:
                        max_k = d[t]
                        max_t = t
print(max_t)
