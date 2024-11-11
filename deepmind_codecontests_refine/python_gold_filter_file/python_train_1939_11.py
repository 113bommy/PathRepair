n = int(input())
weights = [int(i) for i in input().split()]
weights.sort()
total_instability = []

for i in range(len(weights)-1):
  a = weights[i]
  for j in range(i+1, len(weights)):
    instability = 0
    try:
      b = weights[j]
      weights.remove(a)
      weights.remove(b)

      for k in range(0, len(weights), 2):

        instability += weights[k+1] - weights[k]

      weights.append(a)
      weights.append(b)
      weights.sort()
    except:
      pass
    total_instability.append(instability)
print(min(total_instability))