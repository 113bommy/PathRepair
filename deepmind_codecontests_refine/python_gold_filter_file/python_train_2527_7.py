n = int(input())
s = input()
MOD = 10 ** 9 + 7
aCount = 0
abCount = 0
abcCount = 0
qCount = 0
for elem in s:
  if elem == 'c' or elem == "?":
    abcCount += abCount
    if elem == 'c':
      abcCount += 2 * abCount
  if elem == 'b' or elem == "?":
    abCount += aCount
    if elem == 'b':
      abCount += 2 * aCount
  if elem == 'a' or elem == "?":
    aCount += 1
    if elem == 'a':
      aCount += 2
  if elem == "?":
    qCount += 1
print((abcCount * (3 ** qCount) // 27) % MOD)