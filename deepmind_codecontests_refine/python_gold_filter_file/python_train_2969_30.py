num, _, period = input().split()
num = int(num)
if period == "month":
  print(12 if num < 30 else 11 if num < 31 else 7);
elif period == "week":
  print(52 if num < 5 or num == 7 else 53)