while True:
  x = input()
  if x == '0':
    quit()

  print(sum([int(_) for _ in x]))