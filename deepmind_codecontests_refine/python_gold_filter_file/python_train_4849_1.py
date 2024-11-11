import re

t = int(input())

delimiters = "?", ".", " ", ",", "!", ":"
regexPattern = '|'.join(map(re.escape, delimiters))

for i in range(t):
  n = int(input())
  usernames = {x for x in str.split(input(), ' ')}
  m = int(input())
  possibilities = []
  for j in range(m):
    possibilities.append({x for x in usernames})
  messages = []
  for j in range(m):
    messages.append(input())

  for j in range(m):
    if (messages[j][0] != '?'):
      messageSplit = re.split(':', messages[j])
      possibilities[j] = {messageSplit[0]}
    else:
      messageSplit = re.split(regexPattern, messages[j])
      for token in messageSplit:
        if token in usernames:
          possibilities[j] = possibilities[j] - {token}
  changed = True
  while changed:
    changed = False
    for j in range(m):
      if len(possibilities[j]) == 1:
        (poss,) = possibilities[j]
        if j < m-1 and poss in possibilities[j+1]:
          changed = True
          possibilities[j+1] = possibilities[j+1] - possibilities[j]
        if j > 0 and poss in possibilities[j-1]:
          changed = True
          possibilities[j-1] = possibilities[j-1] - possibilities[j]
  worked = True
  for j in range(m):
    if len(possibilities[j]) == 0:
      worked = False
      
  if not worked:
    print("Impossible")
  else :
    for j in range(m):
      poss = next(iter(possibilities[j]))
      if (messages[j][0] == '?'):
        print (poss + messages[j][1:])
      else:
        print(messages[j])
      if (j < m-1):
        possibilities[j+1] = possibilities[j+1] - {poss}

