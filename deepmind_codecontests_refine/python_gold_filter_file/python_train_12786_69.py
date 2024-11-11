n = int(input())

if (n % 7) == 3 or n in (1, 2, 5, 6, 9, 13):
  print("No")
else:
  print("Yes")