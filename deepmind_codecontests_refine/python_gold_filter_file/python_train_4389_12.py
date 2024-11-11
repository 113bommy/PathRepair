k = int(input())

s = list(map(lambda x: ord(x) - ord('a'), input()))
t = list(map(lambda x: ord(x) - ord('a'), input()))

sum_ = []

old = 0

for i in reversed(range(k)):
    s_ = s[i] + t[i] + old
    new = s_ % 26
    sum_.append(new)
    old = s_ // 26

sum_.append(old)

sum_ = list(reversed(sum_))

for i in range(k + 1):
    r = sum_[i] % 2
    sum_[i] //= 2
    if i + 1 <= k:
        sum_[i+1] += 26 * r

print(''.join(map(lambda x: chr(x+ord('a')), sum_[1:])))
