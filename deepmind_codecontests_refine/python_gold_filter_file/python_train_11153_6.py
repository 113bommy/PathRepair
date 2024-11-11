def diff(t, s, n):
    num_paint = 0
    for i in range(n):
        if t[i] != s[i]:
            num_paint += 1
    return num_paint


def build_girland(pattern, n):
    d, m = divmod(n, 3)
    return pattern * d + ('' if m == 0 else pattern[:m])


n = int(input())
s = input()

patterns = ['RGB', 'RBG', 'GRB', 'GBR', 'BRG', 'BGR']
min_paint = n + 1
good_girland = ''
for pattern in patterns:
    true_girland = build_girland(pattern, n)
    num_paint = diff(true_girland, s, n)
    if num_paint < min_paint:
        min_paint = num_paint
        good_girland = true_girland
print(min_paint)
print(good_girland)
