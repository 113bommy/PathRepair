n = int(input())
m = (n * (n - 1)) // 2
s = [set(t.split()[1:]) for t in [input() for i in range(m)]]
q = set(max([s[0], [t - s[0] for t in s[1:] if t & s[0]]][len(s) > 1]))
for t in [q] + [t - q for t in s if t & q]:
    print(len(t), ' '.join(t))