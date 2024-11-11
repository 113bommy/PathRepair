tasks, days = map(int, input().split(' '))
diffs = list(map(int, input().split(' ')))

def maxExclusive(arr, exclusions):
  currMax = 0
  maxIdx = -1
  for i in range(len(arr)):
    if (not i in exclusions) and arr[i] > currMax:
      currMax = arr[i]
      maxIdx = i

  return maxIdx


maxs = []
while len(maxs) < days:
  maxs.append(maxExclusive(diffs, maxs))
maxs.sort()

print(sum(map(lambda x: diffs[x], maxs)))
perDay = []
for i in range(len(maxs)):
  if i == len(maxs) - 1:
    prev = maxs[i - 1] + 1 if i > 0 else 0
    perDay.append(tasks - prev)
  elif i == 0:
    perDay.append(maxs[i] + 1)
  else:
    perDay.append(maxs[i] - maxs[i - 1])
print(' '.join(map(str, perDay)))
