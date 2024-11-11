from collections import defaultdict
t = input()
s = defaultdict(int)
for i in range(len(t) - 9):
    if t[i + 2] == '-' and t[i + 5: i + 9] == '-201' and '2' < t[i + 9] < '6' and '32' > t[i: i + 2] > '00' and '13' > t[i + 3: i + 5] > '00':
        if t[i + 3: i + 5].isdigit():
            if t[i: i + 2].isdigit():
                if t[i: i + 2] < '29': s[t[i: i + 10]] += 1
                elif t[i: i + 2] < '31': 
                    if not (t[i + 3: i + 5] == '02'): s[t[i: i + 10]] += 1
                elif not (t[i + 3: i + 5] in ['04', '06', '09', '11']): s[t[i: i + 10]] += 1
m = max(s.values())
for i in s:
    if s[i] == m:
        print(i)
        break