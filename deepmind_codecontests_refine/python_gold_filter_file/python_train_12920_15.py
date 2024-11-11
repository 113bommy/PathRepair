num = int(input())
list = []
for i in range(0, num):
  list.append([s for s in input()])
for s in list:
  for i in range(0, 3):
    lowercase = 0
    uppercase = 0
    digit = 0
    first_lower = -1
    first_upper = -1
    first_digit = -1
    for i in range(0, len(s)):
      if (s[i].isupper()):
        if first_upper == -1:
          first_upper = i
        uppercase = uppercase + 1
      elif (s[i].islower()):
        if first_lower == -1:
          first_lower = i
        lowercase = lowercase + 1
      else:
        if first_digit == -1:
          first_digit = i
        digit = digit + 1
          
    if digit == 0:
      if lowercase > 1:
        s[first_lower] = "0"
      else:
        s[first_upper] = "0"
    elif lowercase == 0:
      if uppercase > 1:
        s[first_upper] = "a"
      else:
        s[first_digit] = "a"
    elif uppercase == 0:
      if lowercase > 1:
        s[first_lower] = "A"
      else:
        s[first_digit] = "A"
        
for s in list:
  for i in s:
    print(i, end="")
  print()