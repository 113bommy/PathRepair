s = input()
if len(s) < 26:
  for i in range(97, 124):
    if chr(i) not in s:
      break
  print(s + chr(i))
else:
  prep = [s[-1]]
  for i in s[-2::-1]:
    if i > prep[-1]:
      prep.append(i)
    else:
      break
  if len(prep) == 26:
    print(-1)
  else:
    print(s[:-len(prep)-1] + min(i for i in prep if i > s[-len(prep)-1]))

  