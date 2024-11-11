n, k = map(int, input().split(' '))

l = list(map(int, input().split(' ')))

pebbles = []
for i in range(len(l)):
  pebbles.append((l[i], i, []))

pebbles.sort(key=lambda pebble: -pebble[0])

for i in range(pebbles[0][0]):
  pebbles[0][2].append(min(k, i + 1))


bigger = pebbles[0][2][-1]
cnt = pebbles[0][2].count(bigger)

if cnt - pebbles[-1][0] >= 2:
  print("NO")
else:
  print("YES")

  for i in range(1, n):
    pebbles[i][2].extend(pebbles[0][2][::-1][:pebbles[i][0]])
  
  pebbles.sort(key=lambda pebble: pebble[1])
  for pebble in pebbles:
    line = ""
    for c in pebble[2]:
      line += str(c) + ' '
    print(line)