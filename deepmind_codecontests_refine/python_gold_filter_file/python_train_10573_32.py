a, b, c, d = map(int, input().split())
sum = 0
possible_twofiftysix = min(a, c, d)
a -= possible_twofiftysix #possible 32 if not zero left

if a != 0:
    sum += 256 * possible_twofiftysix + 32 * min(a, b)
else:
    sum += 256 * possible_twofiftysix
print(sum)
