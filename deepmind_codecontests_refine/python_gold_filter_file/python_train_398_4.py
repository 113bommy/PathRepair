s = input()
if s[::-1].translate(str.maketrans("bdpq","dbqp")) == s:
  print("Yes")
else:
  print("No")