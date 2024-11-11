t = int(input())
answers = []

for i in range(0,t):

  s = input()
  
  res = ' '
  x = s[0]
  y = s[len(s)-1]

  if (x != y):

    res = s

  else:

    for i in range(1,len(s)):

      if (s[i] != x and s[i] != y):

        res = s[i] + s[1:i] + x + s[i+1:]
        break

  if (res == ' '):

    answers.append(-1)

  else:

    answers.append(res)


for i in range(0, len(answers)):

  print(answers[i])